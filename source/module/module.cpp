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

	//set and get mag window source
	module.def("MagSetWindowTransform", [](int hwnd, std::array<std::array<float, 3>, 3> v)->BOOL
		{
			MAGTRANSFORM matrix ;
			memset(&matrix, 0, sizeof(matrix)); 
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					matrix.v[i][j] = v[i][j];
				}
			}
			BOOL ret = MagSetWindowTransform((HWND) hwnd, &matrix);
			return ret;
		});
	module.def("MagSetWindowSource", [](int hwnd, long left, long top, long right, long bottom)->BOOL 
		{
			RECT magWindowRect = { left,top,right,bottom };
			return MagSetWindowSource((HWND)hwnd, magWindowRect);
		});
	//init and unint mag
	module.def("MagGetWindowSource", [](int hwnd)->std::tuple<long , long , long , long >
	{
		RECT magWindowRect;
		MagGetWindowSource((HWND)hwnd, &magWindowRect);
		return std::make_tuple(magWindowRect.left, magWindowRect.top, magWindowRect.right, magWindowRect.bottom);

	});
	module.def("MagInitialize", &MagInitialize);
	module.def("MagUninitialize", &MagUninitialize);

}