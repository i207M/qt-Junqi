## 声明顺序

- 先函数，再成员
- 先static
- 先Qt，再自定义

## 网络

### 功能

- 连接成功 ok
- 同步棋盘 ok
- 游戏开始 ok
- 下棋 ok
- 认输 ok
- 超时 ok
- 心跳包 ok
- 连接失败

### 逻辑

- 不能操作对方的棋子
- current_player / local_player

### 协议：

第一位：控制位
