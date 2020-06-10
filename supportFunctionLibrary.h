#ifndef supportFunctionLibrary

//Arrays
int splitArray[1];
//Variables
int splitNumberVariable;

void numberSplitFunction(int splitNumberVariable) {

  int sacondNumber = splitNumberVariable % 10;
  int firstNumber = (splitNumberVariable - sacondNumber)/10;
  splitArray[0] =+ firstNumber;
  splitArray[1] =+ sacondNumber;
}


#define supportFunctionLibrary
#endif
