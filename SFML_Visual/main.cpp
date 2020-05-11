#include<SFML/Graphics.hpp>
#include<ctime>

using namespace sf;

int main()
{
    //做一個540x500的視窗
    RenderWindow window(VideoMode(540, 500), "Sodoku!");

    //讀取圖片, 背景
    Texture borad; 
    borad.loadFromFile("image/Borad.png");

    Sprite sBorad(borad);

    while (window.isOpen()) {

        Event e;

        //由視窗的訊息佇列中取得訊息 (滑鼠、鍵盤、選單...)
        while (window.pollEvent(e)) {   
            if (e.type == Event::Closed) //當按下關閉時
                window.close(); //螢幕關閉
        }

         window.clear();    //清除螢幕
         window.draw(sBorad); //將圖片放置在預設位置上
         window.display();  //將緩衝區裡的資料顯示在螢幕上

    }


    
    

    return 0;
}