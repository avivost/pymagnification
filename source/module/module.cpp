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

			/*
			* pybind11::buffer b
			std::vector<ssize_t> source_shape = b.request().shape;
			ssize_t number_of_dimentions = b.request().ndim;
			if (number_of_dimentions != 2
				||  source_shape[0] !=3
				|| source_shape[1] !=3)
			{
				std::string ex = "wrong dimientions should be a matrix of 3x3, got" + std::to_string(source_shape[0]) + "x" + std::to_string(source_shape[1]) + "and with" + std::to_string(number_of_dimentions) + "number of dimentions";
				std::exception(ex);
			}*/
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
	module.def("MagInitialize", &MagInitialize);
	module.def("MagUninitialize", &MagUninitialize);

}