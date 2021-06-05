from typing import Iterable, Tuple, List

WC_MAGNIFIER: str
MS_SHOWMAGNIFIEDCURSOR: int
MS_CLIPAROUNDCURSOR: int
MS_INVERTCOLORS: int
MW_FILTERMODE_EXCLUDE: int
MW_FILTERMODE_INCLUDE: int


def MagInitialize() -> None: ...


def MagUninitialize() -> None: ...


def MagSetWindowTransform(hwnd: int, matrix: Iterable[Iterable[float, float, float],
                                                      Iterable[float, float, float],
                                                      Iterable[float, float, float]]) -> int:
    '''
    Sets the transformation matrix for a magnifier control.

    Parameters
    ----------
    hwnd
        he handle of the magnification window.
    matrix
        A 3x3 magnification transformation matrix

    Returns
    -------
    int
        Returns 1 if successful, or 0 otherwise.
    '''


def MagGetWindowTransform(hwnd: int) -> (Iterable[Iterable[float, float, float],
                                                  Iterable[float, float, float],
                                                  Iterable[float, float, float]]):
    '''
    Retrieves the transformation matrix associated with a magnifier control.

    Parameters
    ----------
    hwnd
        The handle of the magnification window.

    Returns
    -------
    Iterable
        A 3x3 matrix of the magnification transformation matrix
    '''


def MagSetWindowSource(hwnd: int, left: int, top: int, right: int, bottom: int) -> int:
    '''

    Parameters
    ----------
    hwnd
        The handle of the magnification window.
    left
        The left bound of the magnification rectangle
    top
        The top bound of the magnification rectangle
    right
        The right bound of the magnification rectangle
    bottom
        The bottom bound of the magnification rectangle
    Returns
    -------
    int
        Returns 1 if successful, or 0 otherwise.
    '''


def MagGetWindowSource(hwnd: int) -> Tuple[int, int, int, int]:
    '''
    Parameters
    ----------
    hwnd
        The window handle.
    Returns
    -------
    tuple
        A tuple of the bounds of the magnified window rectangle(left, top, right , bottom)

    '''


def MagSetWindowFilterList(hwnd: int, dwFilterMode: int, count: int, pHWND: List[int]) -> int:
    '''

    Parameters
    ----------
    hwnd
        The handle of the magnification window.
    dwFilterMode
        The magnification filter mode. It can be one of the following values:
        # MW_FILTERMODE_INCLUDE (not supported on Windows 7 or newer.)
        # MW_FILTERMODE_EXCLUDE
    count
        The number of window handles in the list.
    pHWND
        The list of window handles.
    Returns
    -------
    int
        Returns 1 if successful, or 0 otherwise


    '''

def MagGetWindowFilterList(hwnd: int) -> Tuple[int, int, List[int]]:
    '''

    Parameters
    ----------
    hwnd
        The magnification window.

    Returns
    -------
    tuple
        A Tuple containing:
            - count of the window handles in the filter list, or -1 if the hwnd parameter is not valid.
            - The filter mode.
            - The list of window handles.


    '''

def MagSetFullscreenTransform(magLevel: float, xOffset: int, yOffset: int) -> int:
    '''
    Changes the magnification settings for the full-screen magnifier.

    Parameters
    ----------
    magLevel
        the full-screen magnifier factor, the value  needs to be between 1.0 and 4096.0
        If this value is 1.0, the screen content is not magnified and no offsets are applied.

    xOffset
        The new x-coordinate offset, in pixels, for the upper-left corner of the magnified view.
        The offset is relative to the upper-left corner of the primary monitor, in unmagnified coordinates.
        The minimum value of the parameter is -262144, and the maximum value is 262144.

    yOffset
        The new y-coordinate offset, in pixels, for the upper-left corner of the magnified view.
        The offset is relative to the upper-left corner of the primary monitor, in unmagnified coordinates.
        The minimum value of the parameter is -262144, and the maximum value is 262144.

    Returns
    -------
    int
        Returns 1 if successful. Otherwise, 0.
    '''

def MagGetFullscreenTransform()->Tuple[float,int,int,int]:
    '''
    Retrieves the magnification settings for the full-screen magnifier.

    Returns
    -------
        tuple

    magLevel : float
        the full-screen magnifier factor
    xOffset : int
         the x-coordinate offset
    yOffset : int
         the y-coordinate offset
    successStatus : int
         1 if successful. Otherwise, 0.




    '''