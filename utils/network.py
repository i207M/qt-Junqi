# TCP的最大报文段长度即MSS一般是1460字节

arr = [...]

ctrl = arr[0]
if ctrl == 0:
    # 由server至client
    # 连接成功
    pass
elif ctrl == 1:
    # 由server至client
    # 同步棋盘，然后游戏开始
    # 直接发送内存，然后memcpy，然后displayAll
    # 注意static的初始化

    # 先由client向server请求
    pass
elif ctrl == 2:
    # 点击start
    # 同时发送一个随机数，点数大者为先手
    pass
elif ctrl == 3:
    # 弃用
    pass
elif ctrl == 4:
    # 鼠标点击事件
    # 内容：两个char
    pass
elif ctrl == 5:
    # 认输
    pass
elif ctrl == 6:
    # 超时
    pass
