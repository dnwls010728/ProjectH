@echo off
setlocal enabledelayedexpansion

:: Unreal Engine 설치 경로 설정 (필요에 따라 수정)
set UE_PATH=C:\Program Files\Epic Games\UE_5.4

:: 현재 디렉토리에서 .uproject 파일 찾기
for %%i in (*.uproject) do (
    set PROJECT_FILE=%%i
    goto :found_project
)
:found_project

if not defined PROJECT_FILE (
    echo Error: No .uproject file found in the current directory.
    goto :end
)

:: 프로젝트 경로를 현재 디렉토리로 설정
set PROJECT_PATH=%cd%\%PROJECT_FILE%

for %%i in (%PROJECT_FILE%) do set PROJECT_NAME=%%~ni

echo Using project: %PROJECT_PATH%

:: UnrealBuildTool 실행
"%UE_PATH%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" ^
-Target="%PROJECT_NAME%Editor Win64 Development" ^
-Project="%PROJECT_PATH%" ^
-Mode=GenerateClangDatabase ^
-WaitMutex ^
-FromMsBuild ^
-Rebuild ^
-CompileDatabase="%cd%\compile_commands.json"

:: 실행 완료 메시지
if %ERRORLEVEL% EQU 0 (
    echo ClangDatabase generation completed successfully.
    if exist "%cd%\compile_commands.json" (
        echo compile_commands.json created at: %cd%\compile_commands.json
    ) else (
        echo Warning: compile_commands.json not found in the expected location.
    )
) else (
    echo An error occurred during ClangDatabase generation.
    echo Error code: %ERRORLEVEL%
)

:end
:: 키 입력 대기
pause