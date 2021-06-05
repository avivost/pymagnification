#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <magnification.h>
#include <string>



PYBIND11_MODULE(pymagnification, module)
{
	module.doc() = "pymagnification";
	module.attr("WC_MAGNIFIER") = WC_MAGNIFIER;
	// Magnifier Window Styles
	module.attr("MS_SHOWMAGNIFIEDCURSOR") = MS_SHOWMAGNIFIEDCURSOR;
	module.attr("MS_CLIPAROUNDCURSOR") = MS_CLIPAROUNDCURSOR;
	module.attr("MS_INVERTCOLORS") = MS_INVERTCOLORS;
	// Filter Modes
	module.attr("MW_FILTERMODE_EXCLUDE") = MW_FILTERMODE_EXCLUDE;
	module.attr("MW_FILTERMODE_INCLUDE") = MW_FILTERMODE_INCLUDE;

	//init and unint mag
	module.def("MagInitialize", &MagInitialize);
	module.def("MagUninitialize", &MagUninitialize);

	//get and set mag window transform
	module.def("MagGetWindowTransform", [](int hwnd)->std::array<std::array<float, 3>, 3>
	{
		MAGTRANSFORM matrix;
		MagGetWindowTransform((HWND)hwnd, &matrix);
		std::array<std::array<float, 3>, 3> v{};

		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				v[i][j] = matrix.v[i][j];
			}
		}
		return v;
	});
	module.def("MagSetWindowTransform", [](int hwnd, std::array<std::array<float, 3>, 3> v)->BOOL
		{
			MAGTRANSFORM matrix;
			memset(&matrix, 0, sizeof(matrix));
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					matrix.v[i][j] = v[i][j];
				}
			}
			BOOL ret = MagSetWindowTransform((HWND)hwnd, &matrix);
			return ret;
		});
	
	//get and set mag window source
	module.def("MagGetWindowSource", [](int hwnd)->std::tuple<long, long, long, long >
		{
			RECT magWindowRect;
			MagGetWindowSource((HWND)hwnd, &magWindowRect);
			return std::make_tuple(magWindowRect.left, magWindowRect.top, magWindowRect.right, magWindowRect.bottom);

		});
	module.def("MagSetWindowSource", [](int hwnd, long left, long top, long right, long bottom)->BOOL 
		{
			RECT magWindowRect = { left,top,right,bottom };
			return MagSetWindowSource((HWND)hwnd, magWindowRect);
		});
	
	//get and set window filters
	module.def("MagGetWindowFilterList", [](int hwnd)->std::tuple<int,int ,std::vector<int>>
		{
			DWORD dwFilterMode;
			int amountOfWindowHandles = MagGetWindowFilterList((HWND)hwnd, &dwFilterMode,0,nullptr);
				std::vector<int> hwnds(amountOfWindowHandles);
				amountOfWindowHandles = MagGetWindowFilterList((HWND)hwnd, &dwFilterMode, amountOfWindowHandles, (HWND*)hwnds.empty() ? NULL : (HWND*)&hwnds[0]);
				return std::make_tuple(amountOfWindowHandles, (int)dwFilterMode, hwnds);
			
		});
	module.def("MagSetWindowFilterList", [](int hwnd, int dwFilterMode, int count, std::vector<int> pHWND)->BOOL
		{

			return MagSetWindowFilterList((HWND)hwnd, (DWORD)dwFilterMode, count, (HWND*)&(pHWND[0]));
		});

	//get and set window full screen transform
	module.def("MagSetFullscreenTransform", &MagSetFullscreenTransform);
	module.def("MagGetFullscreenTransform", []()->std::tuple<float, int, int,int> 
		{
			float pMagLevel = NULL;
			int pxOffset = NULL;
			int pyOffset = NULL;
			int successStatus = MagGetFullscreenTransform(&pMagLevel, &pxOffset, &pyOffset);
			return std::tuple(pMagLevel, pxOffset, pyOffset, successStatus);

	});

	//get and set window color effect
	module.def("MagGetColorEffect", [](int hwnd)->std::array<std::array<float, 5>, 5>
	{
			MAGCOLOREFFECT colormatrix;
			MagGetColorEffect((HWND)hwnd, &colormatrix);
			std::array<std::array<float, 5>, 5> transform{};

			for (size_t i = 0; i < 5; i++)
			{
				for (size_t j = 0; j < 5; j++)
				{
					transform[i][j] = colormatrix.transform[i][j];
				}
			}
			return transform;
	});
	module.def("MagSetColorEffect", [](int hwnd, std::array<std::array<float, 5>, 5> transform)-> int
	{
		MAGCOLOREFFECT colormatrix;
		memset(&colormatrix, 0, sizeof(colormatrix));
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				colormatrix.transform[i][j] = transform[i][j];
			}
		}
		BOOL ret = MagSetColorEffect((HWND)hwnd, &colormatrix);
		return ret;
	});

	//get and set full screen color effect
	module.def("MagGetFullscreenColorEffect", []()->std::array<std::array<float, 5>, 5>
	{
		MAGCOLOREFFECT colormatrix;
		MagGetFullscreenColorEffect(&colormatrix);
		std::array<std::array<float, 5>, 5> transform{};

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				transform[i][j] = colormatrix.transform[i][j];
			}
		}
		return transform;
	});
	module.def("MagSetFullscreenColorEffect", [](std::array<std::array<float, 5>, 5> transform)-> int
	{
		MAGCOLOREFFECT colormatrix;
		memset(&colormatrix, 0, sizeof(colormatrix));
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				colormatrix.transform[i][j] = transform[i][j];
			}
		}
		BOOL ret = MagSetFullscreenColorEffect(&colormatrix);
		return ret;
	});

}