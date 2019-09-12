#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
 
using namespace std;
using namespace cv;
 
int main(){
  VideoCapture cap("teste2.mp4");
  ofstream arquivo;
  ofstream arquivo2;
  Mat frame,histAnt,histAtual,frameBase;
  Mat Equalizado;
  Mat Junto;
  Mat hist;
  int nbins = 64,cont=0;
  float range[] = {0, 256};
  const float *histrange = { range };
  bool acummulate = false;
  bool uniform = true;

  //arquivo.open("histograma1.txt");
  //arquivo2.open("histograma2.txt"); 
  if(!cap.isOpened()){
    cout << "Erro" << endl;
    return -1;
  }//Verifica se video foi aberto
  
int width  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
int height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
 cout<<"width : "<<width<<endl;
 cout<<"height : "<<height<<endl;
 VideoWriter video("Detector.avi",CV_FOURCC('P','I','M','1'),30, Size(width, height),0);

      
  while(1){

     cap>>frameBase;
  cvtColor(frameBase,frameBase,CV_RGB2GRAY);//Transforma para Cinza
  
      calcHist(&frameBase, 1, 0, Mat(), histAnt, 1,
       &nbins, &histrange,
         uniform, acummulate);
    cap >> frame;    
    cvtColor(frame,frame,CV_RGB2GRAY);//Transforma para Cinza  

      // cap>>frame;
      calcHist(&frame, 1, 0, Mat(), histAtual, 1,
       &nbins, &histrange,
       uniform, acummulate);
      cout<<"HistAnt : "<<histAnt.rows<<" "<<histAnt.cols<<endl;
      cout<<"HistAtual : "<<histAtual.rows<<" "<<histAtual.cols<<endl;
      
      for(int i=0;i<64;i++){
	cout<<(int)histAtual.at<uchar>(0,i)<<" ";
	if((int)histAtual.at<uchar>(0,i)!=histAnt.at<uchar>(0,i)){
	  cont++;
	}
      }
      
      if(cont>23){
	cout<<"\nAlgo Passo"<<endl;
	for(int i=0;i<50;i++){
	  for(int j=0;j<50;j++){    
                    frame.at<uchar>(i,j)=0;
  	}
       }
      }
       else{
	for(int i=0;i<50;i++){
	  for(int j=0;j<50;j++){
	  frame.at<uchar>(i,j)=frame.at<uchar>(i,j);
	  }
	}
       }
	cout<<cont<<endl;
	//waitKey();	
      
      cont=0;
      cout<<endl;

      for(int i=0;i<64;i++){
	cout<<(int)histAnt.at<uchar>(0,i)<<" ";
      }
      cout<<endl;
     
	  cont=0;
    if (frame.empty())   break; //Acabar video, fecha while

    //hconcat(frame,Equalizado,Junto);
    
     video.write(frame);   

    
    imshow( "Video", frame );
    
    char c=(char)waitKey(25);
    if(c==27)  break;  //Esc fecha video

  

  }

  cap.release();
  video.release(); 
  //Destrui todos frames
  destroyAllWindows();
     
  return 0;
}
