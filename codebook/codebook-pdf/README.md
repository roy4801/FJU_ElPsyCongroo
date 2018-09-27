Codebook 使用教學
===
<!-- * github專案: [NCTU-PCCA/NCTU_Tmprry](https://github.com/allem40306/Codebook_Sample) -->

* 安裝 [Miktex](https://miktex.org/download)
* 打開 Miktex Console->Packages
* 安裝 xecjk
![](https://i.imgur.com/99zile9.png)
* 安裝字體 [Noto Sans CJK TC](https://briian.com/25754/)
* 打開 codebook 資料夾，會發現有codebook.tex和cotent.tex，前者已經已經幫你設定好，不用在修改，content.tex可自行增加程式。
![](https://i.imgur.com/qQKkcZY.png)
* 接下來我們看content.tex
``` tex
\section{Sample} %標題為sample 

\subsection{Just Sample}%副標題為 Just sample 
\lstinputlisting{hello/world.cpp}%插入一個相對位置在hello/的world.cpp檔案
```
按照這個模式，我們可以插入更多的程式碼
* 編輯好content.tex後，用Texworks打開codebook.tex，綠色開始按鈕右邊選單選"XeLaTex"後，按開始鈕讓他編譯，如果途中遇到要安裝的，讓他安裝或是自己手動安裝
![](https://i.imgur.com/j9bQFQX.png)

