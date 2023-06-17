# 遊戲架構
遊戲使用SDL的第三方函式庫來製作

# 遊戲內容
我推的箱子

# 怎麼執行遊戲

## windows
首先，你的電腦要先安裝mingw   
再來執行以下指令就可以執行
```sh
make
./game
```
### 注意
有些編譯器的make指令是mingw32-make，可能要修改一下

## macOS
首先，電腦要先裝homebrew  
再來執行以下指令
```sh
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
```
安裝完後執行下列指令就可以執行
```sh
make
./game
```
`