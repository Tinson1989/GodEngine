# GodEngine
## about
跟着线上的教程，一步步完善该引擎，然后再做一些修改，从而对引擎深入了解
1. 使用git，路径是https://github.com/Tinson1989/GodEngine.git
2. 目前xmake挺容易使用的，还兼容cmake，所以直接使用xmake作为项目的维护文档
3. 工程有四种类型
    Debug。不对代码进行优化，保留所有符号数据库以便于调试。
    Release。对代码进行优化。

## framework
1. Hardward & Drivers
2. OS 操作系统
3. 3rd Party SDKS
4. Platform Independence Layer, 对诸如网络、文件、线程、定时器等具有平台差异的操作系统功能模块进行抽象封装
5. Core System,游戏引擎中非常核心的模块，直接影响到其他上层模块
    - 内存分配管理（Memory Allocation）
    - 数学运算库（Math Library）
    - 异步文件IO（Asynchronous File IO）
6. Game Asset, 包括模型、纹理、音频、视频、场景描述、特效、shader、材质等等
7. Low Level Renderer, 渲染中的低阶功能部分
    - 抽象图形设备接口，以屏蔽不同的渲染API的差异
    - 实现一些低阶的渲染功能，包括材质系统、光照系统、摄像机系统、调试渲染功能等。
8. Front End(GUI), 
9. Profile & Debugging,
    - 通过Profile数据应该能快速定位引发内存泄漏的模块具体是哪个，以及是具体模块中的那些对象发生了内存泄露
    - 能在开发版本下留下一些有用的Assertion信息，以辅助我们定位问题
10. Skeleton Animation骨骼动画
11. Collision & Physics碰撞与物理模拟
12. Audio音频系统
13. GamePlay Foundation,指的是在游戏引擎中嵌入脚本语言运行时环境，使得上层游戏逻辑可以使用脚本语言进行开发
    - 提高开发效率
    - 保护游戏逻辑
14. Game Specific Subsystems