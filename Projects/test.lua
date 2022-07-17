local rootPath = path.join(os.projectdir(), "Tests")
local includeDir = {"Configuration","Runtime","External/glm"}
target("TestGLM")
    set_group("test")
    set_kind("binary")
    add_files(path.join(rootPath, "GLM", "**.cpp"))
    add_files(path.join(os.projectdir(),"External/glm/glm/**.cpp"))
    add_includedirs(path.join(os.projectdir(),"External/glm"))
    add_headerfiles(path.join(os.projectdir(),"External/glm/**.h"))
    add_headerfiles(path.join(os.projectdir(),"External/glm/**.hpp"))
    add_headerfiles(path.join(os.projectdir(),"External/glm/**.inl"))

target("TestMemoryManager")
    add_defines("_WINDOWS")
    set_group("test")
    set_kind("binary")
    add_files("../Tests/TestMemoryManager.cpp")
    for _,dir in ipairs(includeDir) do
        add_files(path.join(os.projectdir(), dir, "**.cpp"))
        add_headerfiles(path.join(os.projectdir(),dir, "**.hpp"))
        add_headerfiles(path.join(os.projectdir(),dir, "**.h"))
        add_headerfiles(path.join(os.projectdir(),dir, "**.inc"))
        add_includedirs(path.join(os.projectdir(),dir))
        add_includedirs("../")
    end

target("TestD3D")
    set_group("test")
    set_kind("binary")
    add_files("../Tests/TestD3D.cpp")
    add_links("user32","gdi32", "ole32", "d2d1", "d3d11", "d3dcompiler", "opengl32")
   