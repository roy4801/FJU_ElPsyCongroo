struct Node{
    double x,y;
};
struct Line {
    double ax,ay,bx,by;
    Line(){}
    Line(Node A, Node B){
        ax = A.x,ay = A.y;
        bx = B.x,by = B.y;
    }
};
double cross(Line K, double a, double b) {
    double cross1 = (a - K.ax)*(K.by - K.ay);
    double cross2 = (b - K.ay)*(K.bx - K.ax);
    return (cross1 - cross2);
}
bool intersection(Line A, Line B){
    //快速排斥實驗
    if ( max(A.ax,A.bx) < min(B.ax,B.bx) ||
         max(A.ay,A.by) < min(B.ay,B.by) ||
         max(B.ax,B.bx) < min(A.ax,A.bx) ||
         max(B.ay,B.by) < min(A.ay,A.by) ){
        return false;
    }
    //跨立實驗
    if ( cross(B,A.ax,A.ay)*cross(B,A.bx,A.by) > 0 ||
         cross(A,B.ax,B.ay)*cross(A,B.bx,B.by) > 0 ){
        return false;
    }
    return true;
}