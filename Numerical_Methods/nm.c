#include <stdio.h> 
#include <math.h> 
float f(float x) { 

    return (x * x * x - 4 * x - 9); 
    
    } 
    
    int main() { 
    
    float xl, xu, E, xm, fxl, fxu, fxm, Era; int step = 1; 
    
    printf("Enter initial bracketing (xl and xu) and E: "); scanf("%f %f %f", &xl, &xu, &E); 
    
    if (f(xl) * f(xu) > 0) { 
    
    printf("Invalid initial bracket. f(xl) and f(xu) must have opposite signs.\n"); return -1; 
    
    } 
    
    printf("\nStep\t\t xl\t\t xu\t\t xm\t\t f(xm)\n"); 
    
    do { 

        fxl = f(xl); fxu = f(xu); 
        
        xm = (xl + xu) / 2; fxm = f(xm); 
        
        printf("%d\t\t %f\t %f\t %f\t %f\n", step, xl, xu, xm, fxm); if ((fxl * fxm) < 0) { 
        
        xu = xm; 
        
        } else { 
        
        xl = xm; 
        
        } 
        
        Era = fabs((xu - xl) / xm); step++; 
        
        } while (Era > E); 
        
         
        
         
        
        printf("\nRoot = %f\n", xm); printf("\n"); 
        
        printf("Shudarsan Poudel"); return 0; 
        
        return 0; 
        
        }    