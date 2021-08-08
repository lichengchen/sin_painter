# sin_painter
A small Qt project to help painting sine function graph, with tools such as +, *, cursor.

What a elegant image of the sine function!

Authored in 2018/10/3

***

![img](https://github.com/lichengchen/sin_painter/blob/main/p4-1.png?raw=true) 

正弦绘图工具，可用于演示信号的合成.

#### 可调节绘图总点数、精度（采样率）
若采样频率继续减少到一个周期内采不到两个点时，我们将无法从采样点恢复回原始信号。

实际上，根据奈奎斯特采样定理，当采样频率大于信号中最高频率2倍时，采样之后的数字信号完整地保留了原始信号中的信息。

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598826&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>
#### 可调节振幅、频率、相位
调高信号频率（也可以看作相对调低了采样频率），我们看到了漂亮的花纹。信号处理中的眼图现象。

![img](https://github.com/lichengchen/sin_painter/blob/main/p4-1.png)

#### 双函数模式下可模拟相加相乘
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598627&page=2" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>
#### 游标工具精确定位绘图点数值
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598638&page=3" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

***

运行环境：win7或更高

可执行程序下载链接 [SinPainter.exe](https://github.com/lichengchen/sin_painter/releases/download/1.0/SinPainter.exe)

***
