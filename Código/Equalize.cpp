#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
 
using namespace std;
using namespace cv;
 
int main(){
  VideoCapture cap("teste5.mp4");
  ofstream arquivo;
  ofstream arquivo2;
  Mat frame;
  Mat Equalizado;
  Mat Junto;
  
  arquivo.open("histograma1.txt");
  arquivo2.open("histograma2.txt"); 
  if(!cap.isOpened()){
    cout << "Erro" << endl;
    return -1;
  }//Verifica se video foi aberto
  
int width  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
int height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
VideoWriter video("Junto.avi",CV_FOURCC('P','I','M','1'),30, Size(2*width, height),0);
 
  while(1){
    
    cap >> frame;    
    cvtColor(frame,frame,CV_RGB2GRAY);//Transforma para Cinza
    equalizeHist( frame , Equalizado );
    
    if (frame.empty())   break; //Acabar video, fecha while

    hconcat(frame,Equalizado,Junto);
    
    video.write(Junto);   

    
    imshow( "Video", Junto );
    
    char c=(char)waitKey(25);
    if(c==27)  break;  //Esc fecha video

  }
  cap.release();
  video.release(); 
  //Destrui todos frames
  destroyAllWindows();
     
  return 0;
}
