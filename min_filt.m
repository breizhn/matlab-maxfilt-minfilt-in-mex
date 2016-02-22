function y = min_filt(x, filter_length)
% Function to implement a minimum moving window filter.
% It uses the mex function max_min_filt().
%
% ----------------------------------------------------------------------
% Usage: Y = MIN_FILT(X, FILTER_LENGTH)
%
%   input:   ---------
%     x                 numeric vector with input data
%     filter_length     scalar specifying the length of the window
%
%  output:   --------- 
%     y                 filtered data
%
% Author :  (c) Nils L. Westhausen (TGM @ Jade-Hochschule)
%    
% Date   :  22 Feb 2015
% Updated:  -----------
%-----------------------------------------------------------------------

% checking for the right number of input arguments
if nargin < 2
    error('not enough input arguments')
end
% checking input arguments
check_input_max_min_filt(x, filter_length)
% calling mex function
y = max_min_filt(x, filter_length, 2);
end
% end of file