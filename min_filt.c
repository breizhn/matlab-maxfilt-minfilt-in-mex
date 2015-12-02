#include "mex.h"


void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) 
{
    double *data;
    int length_filter = (int)mxGetScalar(prhs[1]);
    int input_length = (int)mxGetNumberOfElements(prhs[0]);
    double *memory;
    double min;
    double *output;
    int n;
    int idx;
    memory = (double*) malloc(sizeof(*memory) * length_filter);
    plhs[0] = mxCreateDoubleMatrix(1, input_length, mxREAL);
    output  = (double*)mxGetData(plhs[0]);
    data = (double*)mxGetData(prhs[0]);
    min = data[0];
    if (nlhs != 1 || nrhs != 2) 
    {
        mexErrMsgTxt("must be called with two input and one output arguments \n");
        return;
    }
    if (!mxIsScalar(prhs[1])) 
    {
        mexErrMsgTxt("second argument must be a scalar \n");
        return;
    }
    if (mxGetNumberOfElements(prhs[0]) < mxGetScalar(prhs[1])) 
    {
        mexErrMsgTxt("the length of the vector is smaller than the filter length");
        return;
    }    
    for (n=0; n<length_filter; n++)
    {
        memory[n] = data[0];
    }
    for (n=0; n<input_length; n++) 
    {
        for (idx=0; idx<length_filter; idx++)
        {
            if ((n + idx) > input_length)
            {
                memory[idx] = data[input_length - 1];
            } 
            else{
                if(idx == (length_filter-1)){
                    memory[idx] = data[n];  
                } 
                else{
                    memory[idx] = memory[idx+1];
                }     
            } 
        }
        min = memory[0];
        for (idx=0; idx<length_filter-1; idx++)
        {
            if(memory[idx+1] < min)
            {
                min = memory[idx+1];
            }
        }
        output[n] = min;
    }
    free(memory);
}