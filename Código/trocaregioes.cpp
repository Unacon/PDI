#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;
  int X,Y,i,j;
  image= imread(argv[1],0);
  if(!image.data)    cout << "nao abriu" << endl;
  Mat imagef(image.rows,image.cols,0);
  X=image.cols/2 ;
  Y=image.rows/2;
  cout<<X<<" "<<Y<<endl;
  for(i=0;i<image.cols;i++){
    for(j=0;j<image.rows;j++){
      if (i<=X && j<=Y) imagef.at<uchar>(j,i)=image.at<uchar>(Y+j,X+i);
      if (i>=X && j<=Y) imagef.at<uchar>(j,i)=image.at<uchar>(Y+j,i-X);
      if (i<=X && j>=Y) imagef.at<uchar>(j,i)=image.at<uchar>(j-Y,i+X);
      if (i>=X && j>=Y) imagef.at<uchar>(j,i)=image.at<uchar>(j-Y,i-X);
      
    }
  }
  
  imshow("ImagemOriginal",image);
  waitKey();
				
  imshow("ImagemTrocada", imagef);
  imwrite("imgtrocada.png",imagef);
  waitKey();  
  return 0;
}
