from typing import Iterable, Tuple, List

WC_MAGNIFIER: str
MS_SHOWMAGNIFIEDCURSOR: int
MS_CLIPAROUNDCURSOR: int
MS_INVERTCOLORS: int
MW_FILTERMODE_EXCLUDE: int
MW_FILTERMODE_INCLUDE: int


def MagSetWindowTransform(hwnd: int, matrix: Iterable[Iterable[float, float, float],
                                                      Iterable[float, float, float],
                                                      Iterable[float, float, float]]) -> int:
    """
    Use to set the magnification transformation matrix on the window provided by the window handle

    :param hwnd: The handle of the magnification window.
    :param matrix: A 3x3 matrix of the magnification transformation
    :return
    Returns 1 if successful, or 0 otherwise.
    """


def MagGetWindowTransform(hwnd: int) -> (Iterable[Iterable[float, float, float],
                                                  Iterable[float, float, float],
                                                  Iterable[float, float, float]]):
    """
    Use to set the magnification transformation matrix on the window provided by the window handle

    :param hwnd: The handle of the magnification window.
    :return
    A 3x3 matrix of the magnification transformation
    """


def MagSetWindowSource(hwnd: int, left: int, top: int, right: int, bottom: int) -> int:
    """

    :param hwnd: The handle of the magnification window.
    :param left: The left bound of the magnification rectangle
    :param top: The top bound of the magnification rectangle
    :param right: The right bound of the magnification rectangle
    :param bottom: The bottom bound of the magnification rectangle
    :return:
    Returns 1 if successful, or 0 otherwise.
    """


def MagGetWindowSource(hwnd: int) -> Tuple[int, int, int, int]:
    """
    :param hwnd:The window handle.
    :return: A tuple of the bounds of the magnified window rectangle(left, top, right , bottom )

    """
def MagSetWindowFilterList(hwnd : int ,dwFilterMode : int,count: int , pHWND :List[int])->int:
    """
    
    :param hwnd: The handle of the magnification window.
    :param dwFilterMode: The magnification filter mode. It can be one of the following values:
        MW_FILTERMODE_INCLUDE Note: This value is not supported on Windows 7 or newer.
        MW_FILTERMODE_EXCLUDE
    :param count: The number of window handles in the list.
    :param pHWND: The list of window handles.
    :return: 
    Returns 1 if successful, or 0 otherwise.
    """

def MagGetWindowFilterList(hwnd:int)->Tuple[int,int,List[int]]:
    """

    :param hwnd: The magnification window.
    :return:
    A Tuple containing:
    - count of window handles in the filter list, or -1 if the hwnd parameter is not valid.
    - The filter mode.
    - The list of window handles.
    """

