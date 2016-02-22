#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) 
{
    double *data = (double*)mxGetData(prhs[0]);;
    int length_filter = (int)mxGetScalar(prhs[1]);
    int filter_type = (int)mxGetScalar(prhs[2]);
    int input_length = (int)mxGetNumberOfElements(prhs[0]);
    double memory[input_length];
    double max = (double)data[0];
    int n;
    int idx;
    plhs[0] = mxCreateDoubleMatrix(1, input_length, mxREAL);
    double *output = (double*)mxGetData(plhs[0]);
    
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
        max = memory[0];
        for (idx=0; idx<length_filter-1; idx++)
        {
            if(filter_type == 1) // max filter
            {
                if(memory[idx+1] > max)
                {
                    max = memory[idx+1];
                }
            }
            else if(filter_type == 2) // min filter
            {
                if(memory[idx+1] < max)
                {
                    max = memory[idx+1];
                }
            }
        }
        output[n] = max;
    }
}