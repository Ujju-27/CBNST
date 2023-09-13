#include<stdio.h>
#include<math.h>

double polyfunc(double x){
    return (x*x*x-4*x-9);
}

double diffFunc(double x){ 
    double ans = 3*x*x-4;
    return ans; 
}


double hx(double x){
    double ans = (polyfunc(x)/diffFunc(x));
    return ans; 
}

int step = 0;
void calNewtonRaphson(double x){
    
    double y = x - (hx(x));
    step++;
    printf("%d Iteration and the value of x is = %lf\n" , step, y);
    if(fabs(y - x) <= 0.0001){
        printf("The steps are = %d\n" , step);
        return;
    }
    
    calNewtonRaphson(y);
    
}

int main(){
    double a , b;
    
    printf("Enter guessed range  = ");
    scanf("%lf%lf" ,&a,&b);
    
    if(polyfunc(a) * polyfunc(b) < 0)
    {
        double x;
        printf("Root are accepted !!!\n");
        x= (a + b)/2;
        printf("The value of x is = %lf\n" , x);
        calNewtonRaphson(x);
    }
    else{
        printf("0ops invalid input !!!");
    }
    return 0;
}
