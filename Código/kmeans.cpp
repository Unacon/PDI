#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv ){
  int nClusters = 6;
  Mat rotulos;
  int nRodadas = 1;
  Mat centros; 
  
  Mat img = imread( argv[1], CV_LOAD_IMAGE_COLOR);
  Mat samples(img.rows * img.cols, 3, CV_32F);
  for(int i=0;i<10;i++){
  for( int y = 0; y < img.rows; y++ ){
    for( int x = 0; x < img.cols; x++ ){
      for( int z = 0; z < 3; z++){
        samples.at<float>(y + x*img.rows, z) = img.at<Vec3b>(y,x)[z];
	  }
	}
  }
  
  kmeans(samples,
		 nClusters,
		 rotulos,
		 TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001),
		 nRodadas,
		 KMEANS_RANDOM_CENTERS,
		 centros );


  Mat rotulada( img.size(), img.type() );
  for( int y = 0; y < img.rows; y++ ){
    for( int x = 0; x < img.cols; x++ ){ 
	  int indice = rotulos.at<int>(y + x*img.rows,0);
	  rotulada.at<Vec3b>(y,x)[0] = (uchar) centros.at<float>(indice, 0);
	  rotulada.at<Vec3b>(y,x)[1] = (uchar) centros.at<float>(indice, 1);
	  rotulada.at<Vec3b>(y,x)[2] = (uchar) centros.at<float>(indice, 2);
	}
  }
  imshow( "clustered image", rotulada );
  if(i==0){
  imwrite("foto0.jpg", rotulada);
  }
  if(i==1){
   imwrite("foto1.jpg", rotulada);
  }
    if(i==2){
   imwrite("foto2.jpg", rotulada);
  }
      if(i==3){
   imwrite("foto3.jpg", rotulada);
  }
        if(i==4){
   imwrite("foto4.jpg", rotulada);
  }
	  if(i==5){
   imwrite("foto5.jpg", rotulada);
  }
	    if(i==6){
   imwrite("foto6.jpg", rotulada);
  }
	      if(i==7){
   imwrite("foto7.jpg", rotulada);
  }
  if(i==8){
   imwrite("foto8.jpg", rotulada);
  }
  if(i==9){
   imwrite("foto9.jpg", rotulada);
  }
  }
  
  waitKey( 0 );
}
