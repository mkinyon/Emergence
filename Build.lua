-- premake5.lua
workspace "Emergence"
   architecture "x64"
   configurations { "Debug", "Release" }
   startproject "Emergence"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

-- copy the SDL2.dll file
include "App/Build-App.lua"
