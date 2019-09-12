#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;
  int width, heigth, objetos=0, i, j,comburaco=0,semburaco=0;
  CvPoint p(0,0);

  image = imread(argv[1],0);
  if(!image.data){
    cout<<"Nao abriu\n";
    return(0);
  }

  imshow("Contador",image);
  waitKey();
  
  width=image.size().width;
  heigth=image.size().height;
  
  for(i=0;i<heigth;i++){  
    if(image.at<uchar>(i,0)==255){
       p.x=0;
       p.y=i;
          floodFill(image,p,0);
    }
    if(image.at<uchar>(i,width-1)==255){
       p.x=width-1;
       p.y=i;
        floodFill(image,p,0);
    }
      }
   for(j=0;j<width;j++){  
     if(image.at<uchar>(0,j)==255){
       p.x=j;
       p.y=0;
        floodFill(image,p,0);
      }
    
     if(image.at<uchar>(heigth-1,j)==255){
       p.x=j;
       p.y=heigth-1;
       floodFill(image,p,0);
      }
  }

   for(i=0;i<heigth;i++){
    for(j=0;j<width;j++){
      if(image.at<uchar>(i,j)==255){
	objetos++;
	p.x=j;
	p.y=i;
	floodFill(image,p,objetos);
      }
    }
  }
    imshow("Contador",image);
    imwrite("labeling.png", image);
    waitKey();
   
   p.x=0;
   p.y=0;
   floodFill(image,p,255);
   imwrite("FundoBranco.png",image);
   
   for(i=0;i<heigth;i++){
    for(j=0;j<width;j++){
      if(image.at<uchar>(i,j)==0 && image.at<uchar>(i,j-1)!=255){
	comburaco++;
	p.x=j;
	p.y=i;
	floodFill(image,p,255);
	p.x=j-1;
	floodFill(image,p,255);
      }
    }
  }
   imshow("BolhasS",image);
   imwrite("labeling2.png",image);
   
   for(i=0;i<heigth;i++){
    for(j=0;j<width;j++){
      if(image.at<uchar>(i,j)!=255){
	semburaco++;
	p.x=j;
	p.y=i;
	floodFill(image,p,255);
      }
    }
  }
    
  cout<<"Quantidade de Bolhas : "<<objetos<<endl;
  cout<<"Quantidade de Bolhas com Buracos : "<<comburaco<<endl;
  cout<<"Quantidade de Bolhas sem Buracos : "<<semburaco<<endl;
  waitKey();
  return 0;
}








		 

		    
		    
		   
