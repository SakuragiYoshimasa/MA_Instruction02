#pragma once

#include "ofMain.h"

class Polygon3d {
    
private:
    ofPoint mPolygonPosition = ofPoint(0,0,0);
    int mPolygonType = 0; //0:Box 1:Sphere
    int mPolygonSize = 0; //10~100
    
public:
    Polygon3d(){};
    ~Polygon3d(){};
    /* また、クラスにはそのクラスがdelete演算子で消去される際に実行される特別な関数を定義することも可能です。
     * この消去の際の関数を「デストラクタ (destructer)」と呼びます。デストラクタはクラス名の先頭にチルダ「~」をつけて関数名とします。
     */
    void setPolygonPosition(float x, float y, float z){
        mPolygonPosition.set(x, y, z);
    }
    void setPolygonPosition(ofPoint position){
        mPolygonPosition = position;
    }
    void setPolygonType(int id){
        mPolygonType = id;
    }
    void setPolygonSize(int size){
        mPolygonSize = size;
    }
    ofPoint getPolygonPosition(){
        return mPolygonPosition;
    }
    int getPolygonType(){
        return mPolygonType;
    }
    int getPolygonSize(){
        return mPolygonSize;
    }
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofBoxPrimitive boxPrimitive;
    ofSpherePrimitive spherePrimitive;
    ofCamera camera;
    
    vector<Polygon3d *> polygons;//ポインタ型で宣言,Polygon3dクラスのオブジェクトをさしているポインタを格納する配列なので、ポインタ型で宣言
    
    float objectSizeScale = 1.0;
    double cameraSpeed = 0.0;
    double cameraPosition = 0.0;
    bool accelFlag = false;
};
