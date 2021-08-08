# sin_painter
A small Qt project to help painting sine function graph, with tools such as +, *, cursor.


Authored in 2018/10/3

***

![img](https://github.com/lichengchen/sin_painter/blob/main/p4.jpg) 

正弦绘图工具，可演示信号的采样、合成

***

#### 可调节绘图总点数、精度（采样率）
若采样频率继续减少到一个周期内采不到两个点时，我们将无法从采样点恢复回原始信号。

实际上，根据奈奎斯特采样定理，当采样频率大于信号中最高频率2倍时，采样之后的数字信号完整地保留了原始信号中的信息。

![img](https://github.com/lichengchen/sinPainter/blob/main/4-1.gif) 
#### 可调节振幅、频率、相位
调高信号频率（也可以看作相对调低了采样频率），我们看到了漂亮的花纹。信号处理中的眼图现象。

![img](https://github.com/lichengchen/sin_painter/blob/main/p4-1.png)

#### 双函数模式下可模拟相加相乘
![img](https://github.com/lichengchen/sinPainter/blob/main/4-2.gif) 
#### 游标工具精确定位绘图点数值
![img](https://github.com/lichengchen/sinPainter/blob/main/4-3.gif) 

