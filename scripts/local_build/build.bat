set GMIO_LOCAL_CI_ROOT=%~dp0
call %GMIO_LOCAL_CI_ROOT%\_uservars.bat
set GMIO_ROOT=%GMIO_LOCAL_CI_ROOT%\..\..
set PATH_MSVC2010=%VS100COMNTOOLS%
set PATH_MSVC2012=%VS110COMNTOOLS%
set PATH_MSVC2013=%VS120COMNTOOLS%
set PATH_MSVC2015=%VS140COMNTOOLS%
set PATH=%PATH_CMAKE%;%PATH_DOXYGEN%;%PATH_JOM%;%PATH%
set PATH_ORIGINAL=%PATH%

cmake --version
cd %GMIO_BUILD_ROOT%
call %GMIO_LOCAL_CI_ROOT%\_userbuilds.bat
pause
