#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;
  int P1[2],P2[2];

  image= imread(argv[1],0);
  if(!image.data)
  cout << "nao abriu" << endl;
  imshow("Imagem Inicial",image);
   
  cout<<"Tamanho da imagem : "<<image.rows<<"x"<<image.cols<<"\n";
  cout<<"Digite o ponto P1(x,y)\n";//Ponto extremo esquerdo
  cin>>P1[0]>>P1[1];//x=linha y=coluna
  cout<<"Digite o ponto P2(x,y)\n";//Ponto extremo direito
  cin>>P2[0]>>P2[1];//x=linha e y=coluna
  
  if(P1[0]>=0 && P1[1]<image.rows && P2[0]>=P1[0] && P2[1]>=P2[1]){
      for(int i=P1[0];i<P2[0];i++){
	for(int j=P1[1];j<P2[1];j++){
                    image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
  	}
      }
  imshow("janela", image);
  imwrite("dota.jpg",image);
  waitKey();
  }
  
  return 0;
}
