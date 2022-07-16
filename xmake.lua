add_rules("mode.debug", "mode.release")

-- add_requires("glslang", {configs = {binaryonly = true}})
-- target("shader")
--     set_kind("binary")
--     add_rules("utils.glsl2spv", {outputdir = "build", bin2c = true})
--     add_files("Asset/Shader/*.vert")
--     add_files("Asset/Shader/*.frag")
--     add_packages("glslang")

target("core")
    set_kind("static")
    add_files("Framework/**.cpp")
    add_headerfiles("Framework/**.hpp")
    add_includedirs("Framework")

target("windows")
    set_kind("binary")
    add_deps("core")
    add_includedirs("Framework")
    add_files("Platform/Windows/**.cpp")
    add_links("user32","gdi32", "ole32", "d2d1", "d3d11", "d3dcompiler", "opengl32")
    add_defines("_USE_OPENGL")
    after_build(function(target)
        if is_mode("debug") then
            os.cp(path.join(os.projectdir(), "Asset/Shader/*.*") , "$(buildir)/windows/x64/debug")
        else
            os.cp(path.join(os.projectdir(), "Asset/Shader/*.*") , "$(buildir)/windows/x64/release")
        end
    end)

target("empty")
    set_kind("binary")
    add_deps("core")
    add_includedirs("Framework")
    add_files("Platform/Empty/**.cpp")
    set_default(true)



--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

