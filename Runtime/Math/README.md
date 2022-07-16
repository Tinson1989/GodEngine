# 数学运算库

渲染流程中需要计算各种空间变换和各种裁剪优化算法，物理模拟中的碰撞检测算法，动画模块中骨骼矩阵的计算，都离不开数学运算库。数学运算的实现直接影响到所有其他模块的运算效率。在一般商用引擎中，这个部分都会进行深度优化，以达到极致的性能表现，避免成为引擎的性能瓶颈

## DirectXMath
https://docs.microsoft.com/en-us/windows/win32/dxmath/directxmath-portal

## Eigen
https://eigen.tuxfamily.org/index.php?title=Main_Page

## glm
https://github.com/g-truc/glm

## todolist
1. 先编写这部分的内容
2. 后续引入glm这个数学库

### 点与向量
- 加减
- 点乘
- 叉乘
- 缩放
- 归一化

### 矩阵
- 加法
- 标量乘法
- 转置
- 矩阵乘法
- 求逆

### 万向锁和四元数
