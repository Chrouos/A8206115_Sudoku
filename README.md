# 數獨小遊戲
###### 一年級下學期 —— 物件導向期末專題

題目：數獨  
組長：黃懷萱  
組員：王韻淳、林詠涵
***

**說明**：  
遊戲目的為將 9x9 的方塊填滿數字， 讓每一行、每一列及每一格 3x3 的方塊中，都有1至9的數字，不可重複。  
也是一款考驗腦力的遊戲。

**功能**：(有待思考)  
- [ ] 復原功能
- [x] 除錯輔助
- [x] 改錯功能
- [x] 計時
- [x] 返回功能


----
+ `grid: 產生題目`   
      - `Generator()：作用為製作題目  `       
      -`checkPutInGrid()：去做確認，壁面失敗太多次產生錯誤題目，可自動判斷後再重新製作一個新的題目  `    
      -`print()：可以幫忙做輸出的動作   `   
      -`operator[]：為了方便操作，寫了一個operator來幫忙轉成int來使用   `      
      
+ `puzzleCheck：確認是否有重複數字，並且可以用於main函式之中幫忙除錯，也可利用在Generator() 便於製作題目`   
      -`nReaptingStraight：判斷直行是否出現重複數字`     
      -`nReaptingHorizontal：判斷橫行是否出現重複數字`    
      -`nReaptingCroner：判斷直、行是否出現重複數字`    
      -`nReaptingBlock：判斷區間是否出現重複數字`    
      
+ `sloveSudoku：確認解答各數，保證挖洞後的題目只有一個正確解答`   
      
+ `dig：挖空題目，目前只設置簡單版本，30格填空`

***
**備註**：

一、輸入位置後發現輸入錯誤，可以再輸入數字的位置填入-1，讓其重新開始    
二、程式會自動判斷輸入的數字是否重複，例如直、行、區之間不可有重複數字，方便使用者遊玩   
三、遊戲中會自動幫忙計時，可以看看自己玩了多久時間唷   
