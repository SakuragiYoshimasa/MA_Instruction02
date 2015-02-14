#include "ofApp.h"
#define NUM_OF_POLYGONS 20

/*
 * ofAppクラスのsetup()メソッドを定義する。
 * ::は「スコープ解決演算子」と呼ばれるもので、名前空間のduplicateをさける役割がある
 * namespaceもしくはClassで分ける
 * C++ において、::（スコープ解決）演算子は、スコープ外の変数名または関数名のグローバル識別子です。
 * どのクラスのsetup()なのかを明示している
 */

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetSphereResolution(100);
    ofEnableDepthTest(); //enable depth test (for drawing correctly)
    for (int i=0; i<NUM_OF_POLYGONS; i++){
        polygons.push_back(new Polygon3d());//動的配列生成
        /*
         * 動的配列Polygon3d型のpolygonsの
         * 最後尾に引数のとデータを付け足す
         * 「new演算子」を使用することで、オブジェクトを任意のタイミングで動的に生成することが可能となります。
         * new演算子は、記憶領域の空き領域(ヒープ heap)から指定したクラスを大きさの領域を確保します。
         * その際、new演算子は確保した領域のアドレスを返します。この動的な記憶領域のエイリアスを使用するために、ポインタを利用します。
         * 上記の場合、new Polygon3d()で生成されるものは Polygon3dクラスのオブジェクトそのものではなく、Polygon3dクラスのオブジェクトをさしているポインタである
         */
    }
    for (int i=0; i<polygons.size(); i++) {
        polygons.at(i)->setPolygonPosition(ofRandom(-2000, 2000),ofRandom(-2000, 2000),ofRandom(-2000, 2000));//動的配列の要素の座標を初期化
        /*
         * vector.at(x)はx番目の動的配列データへのアクセスを行う、vector[x]でも同じ動作を実行できる
         * 今回生成されて、配列に格納されているのは、オブジェクトへのポインタであるから、アロー演算子を使う
         * (動的に生成したオブジェクトのポインタから、そのメンバであるメソッドやプロパティを参照するには、ドット演算子「.」の代わりに、アロー演算子「->」を用います。)
         */
        polygons.at(i)->setPolygonType(floor(ofRandom(2)));
        polygons.at(i)->setPolygonSize(floor(ofRandom(10,100)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    objectSizeScale = 1 + 0.3 * pow(sin((double)ofGetElapsedTimeMillis()/100),6.0);
    
    if (accelFlag) cameraSpeed += 0.005;
    else if (cameraSpeed > 0) cameraSpeed -= 0.020;
    else cameraSpeed = 0;
    cameraPosition += cameraSpeed;
    
    camera.setPosition(2000*sin(cameraPosition), 0, 2000*cos(cameraPosition));
    camera.lookAt(ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    camera.begin();
    
    for (int i = 0; i<polygons.size(); i++) {
        ofSetColor(ofColor::fromHsb(0, 255, ofRandom(128,255)));
        ofLine(ofPoint(0,0,0), polygons.at(i)->getPolygonPosition());
        switch (polygons.at(i)->getPolygonType()) {
            case 0:
                ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                boxPrimitive.setPosition(polygons.at(i)->getPolygonPosition());
                boxPrimitive.set(polygons.at(i)->getPolygonSize()*objectSizeScale);
                boxPrimitive.drawWireframe();
                break;
            case 1:
                ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                spherePrimitive.setPosition(polygons.at(i)->getPolygonPosition());
                spherePrimitive.setRadius(polygons.at(i)->getPolygonSize()*objectSizeScale/2);
                spherePrimitive.drawWireframe();
            default:
                break;
        }
    }
    
    camera.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        accelFlag = true;
    } else if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' '){
        accelFlag = false;
    }else if(key=='d'&& polygons.size()>0){
        /* 動的に生成されたオブジェクトは、delete演算子を用いて破棄することが可能ですが。
         * detele演算子でオブジェクトを破棄することで、
         * 確保された領域は解放されまたヒープ領域(空領域)に戻され、再利用できるようになります。
         * new演算子とdelete演算子を適切なタイミングで使用することで、
         * メモリを効率良く使用しながらプログラムを実行することが可能となります。
         */
        //polygons.at(polygons.size()-1).pop_back();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
