#include<SFML/Graphics.hpp>
#include<ctime>
using namespace sf;
using namespace std;

//去確認 直、橫、區是否相加為45
bool check(int sGrid[9][9]) {

    int checkHorizontal[9] = {};
    int checkStraight[9] = {};
    int checkThreeThree[9] = {};

    int k = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // 橫的加起來是45 
            checkHorizontal[i] += sGrid[i][j];
            // 直的加起來是45
            checkStraight[i] += sGrid[j][i];
            // 3*3加起來是45
            if (j <= 2)
                checkThreeThree[k] += sGrid[i][j];
            else if (j <= 5)
                checkThreeThree[k + 1] += sGrid[i][j];
            else if (j <= 8)
                checkThreeThree[k + 2] += sGrid[i][j];

        }
        if (i == 2 || i == 5 || i == 8)
            k += 3;
    }
    
    for (int i = 0; i < 9; i++) {
        if (checkHorizontal[i] != 45 || checkStraight[i] != 45 || checkThreeThree[i] != 45)
            return false;
        else
            return true;
    }
}


int main()
{

    srand(time(0));

    //做一個 420x400 的視窗
    RenderWindow window(VideoMode(425, 400), "Sodoku!");

    //數值設定
    int width = 47; //格子長
    int height = 44; //格子寬
    int grid[9][9]; //九個數字
    int sGrid[9][9];  //for showing

    //讀取圖片
    Texture borad;  //背景
    borad.loadFromFile("image/Borad.png");
    Sprite sBorad(borad);

    Texture number; //數字
    number.loadFromFile("image/number.png");
    Sprite sNumber(number);

    ////////// 計算 //////////

    //當 相加不等於45時 就一直做
    while (check(grid) == false) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                //由左到右取亂數 1～9
                grid[i][j] = (rand() % 9) + 1;

                //橫的 1～9 不重複
                for (int s = 0; s < j; s++) {
                    if (grid[i][j] == grid[i][s]) {
                        j--;
                        break;
                    }
                }

                //TODO: 直的 1～9 不重複

                //TODO: 區塊 1～9 不重複

            }
        }
    }



    while (window.isOpen()) {

        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / width;
        int y = pos.y / height;

        Event e;

        //由視窗的訊息佇列中取得訊息 (滑鼠、鍵盤、選單...)
        while (window.pollEvent(e)) {

            //當按下關閉時
            if (e.type == Event::Closed)
                window.close(); //螢幕關閉

            //當按下"滑鼠"且"左鍵"時
            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left) {

                }
            }


        }

        window.clear(Color::White);    //清除螢幕
        window.draw(sBorad); //將圖片放置在預設位置上
        window.display();  //將緩衝區裡的資料顯示在螢幕上

    }





    return 0;
}





/*
//字型物件
Font font;
if (!font.loadFromFile("arial.ttf")) {  //使用arial.ttf
    return EXIT_FAILURE;
}

//數字
string num = "0";
Text digital(num, font, 30);
digital.setFillColor(Color::Red);
*/