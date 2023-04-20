//External Functions

float __min_float(float x, float y) {
    return x > y ? y : x;
}

float foo(float x,float y){
  return x+y;
    }

float bar(float x, float y, float z){
  return __min_float(x, __min_float(y, z));
}
