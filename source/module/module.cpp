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

	//get and set mag window transform
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
	//get and set mag window source
	module.def("MagSetWindowSource", [](int hwnd, long left, long top, long right, long bottom)->BOOL 
		{
			RECT magWindowRect = { left,top,right,bottom };
			return MagSetWindowSource((HWND)hwnd, magWindowRect);
		});
	module.def("MagGetWindowSource", [](int hwnd)->std::tuple<long, long, long, long >
		{
			RECT magWindowRect;
			MagGetWindowSource((HWND)hwnd, &magWindowRect);
			return std::make_tuple(magWindowRect.left, magWindowRect.top, magWindowRect.right, magWindowRect.bottom);

		});
	//get and set window filters
	module.def("MagSetWindowFilterList", [](int hwnd, int dwFilterMode, int count, std::vector<int> pHWND)->BOOL 
		{

			return MagSetWindowFilterList((HWND)hwnd, (DWORD)dwFilterMode, count,(HWND*)&(pHWND[0]));
		});
	module.def("MagGetWindowFilterList", [](int hwnd)->std::tuple<int,int ,std::vector<int>>
		{
			DWORD dwFilterMode;
			int amount_of_window_handles=MagGetWindowFilterList((HWND)hwnd, &dwFilterMode,0,nullptr);
				std::vector<int> hwnds(amount_of_window_handles);
				amount_of_window_handles = MagGetWindowFilterList((HWND)hwnd, &dwFilterMode, amount_of_window_handles, (HWND*)hwnds.empty() ? NULL : (HWND*)&hwnds[0]);
				return std::make_tuple(amount_of_window_handles, (int)dwFilterMode, hwnds);
			
		});
	//init and unint mag
	module.def("MagInitialize", &MagInitialize);
	module.def("MagUninitialize", &MagUninitialize);

}