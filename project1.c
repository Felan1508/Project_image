/// @file main .c
# include <stdio.h>
# define STB_IMAGE_IMPLEMENTATION
# include "D:\project1\headers\stb_image.h"
# define STB_IMAGE_WRITE_IMPLEMENTATION
# include "D:\project1\headers\stb_image_write.h"
/**
* Delete a quarter of the image
* @param [in] image the input image
* @param [in] width the width of the image
* @param [in] height the height of the image
* @param [in] channel the channel of the image
*/
/*unsigned char mask_image ( unsigned char *image ,unsigned char *image2,unsigned char *image3, int width , int height , int channel)
{
for (int i = 0; i < height ; i++)
{
for (int j = 0; j < width ; j++)
{
for ( int k = 0; k < channel ; k++)
{ if( 
image [i * width * channel + j * channel + k] ==image2 [i * width * channel + j * channel + k]){
    image [i * width * channel + j * channel + k]=image3 [i * width * channel + j * channel + k];
}
}
}
}
}*/
unsigned char erase_green_background( unsigned char * image1 , unsigned char * image2, unsigned char * image3, int width , int height , int channel) {
 for (int i = 0; i < height ; i ++) {
   for (int j = 0; j < width ; j ++)  {
      int dif = 0;
     for (int k = 0; k < channel ; k ++) {
       dif += abs(image1 [ i * width * channel + j * channel + k ] -  image2 [ i * width * channel + j * channel + k ]);
        // image2 [ i * width * channel + j * channel + k ] = image3 [ i * width * channel + j * channel + k ];
         }
         if(dif < 160) {
          for(int k = 0; k < channel ; k++) {
            image1 [ i * width * channel + j * channel + k ] = image3 [ i * width * channel + j * channel + k ];
          }
         }
       }
     }
   }
int main ()
{
// declare variables
int width , height , channel ;
char path_img1 [] = "D:/project1/image/foreground.png";
char path_img2 [] = "D:/project1/image/background.png";
char path_img3 [] = "D:/project1/image/new_background.png";
char save_path [] = "D:/project1/image/product.png";

// read image data
unsigned char * image1 = stbi_load ( path_img1 , &width , &height , & channel , 0);
if ( image1 == NULL )
{
printf ("\nError in loading the image \n");
exit (1) ;
}
//printf (" Width = %d\n Height = %d\nChannel = %d\n", width , height , channel );

unsigned char * image2 = stbi_load ( path_img2 , &width , &height , & channel , 0);
if ( image2 == NULL )
{
printf ("\nError in loading the image \n");
exit (1) ;
}
//printf (" Width = %d\n Height = %d\nChannel = %d\n", width , height , channel );

unsigned char * image3 = stbi_load ( path_img3 , &width , &height , & channel , 0);
if ( image3 == NULL )
{
printf ("\nError in loading the image \n");
exit (1) ;
}
//printf (" Width = %d\n Height = %d\nChannel = %d\n", width , height , channel );
// fill image with black pixels
erase_green_background (image1 , image2, image3, width , height , channel );
// save image
stbi_write_png ( save_path , width , height , channel , image1 , width * channel );
printf (" New image saved to %s\n", save_path );

}