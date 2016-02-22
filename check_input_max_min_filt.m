function check_input_max_min_filt(x, filter_length)
% Function to check the input arguments of the functions max_filt() and
% min_filt() for the mex function max_min_filt().
%
% ----------------------------------------------------------------------
% Usage: CHECK_INPUT_MAX_MIN_FILT(X, FILTER_LENGTH)
%
%   input:   ---------
%     x                 numeric vector with input data
%     filter_length     scalar specifying the length of the window
%
% Author :  (c) Nils L. Westhausen (TGM @ Jade-Hochschule)
%    
% Date   :  22 Feb 2015
% Updated:  -----------
%-----------------------------------------------------------------------

% checking existence of the mex file
if exist('max_min_filt', 'file') ~= 3
    error('mex file max_min_filt is missing, please compile it')
end
% checking for the right number of input arguments
if nargin < 2
    error('not enough input arguments')
end
% checking filter length
if length(x) < filter_length
    error('filter_length has to be greater than the input length')
end
% checking if x is a vector
if ~any(size(x) == 1)
    error('x must be a vector')
end
% checking if filter length is a scalar
if length(filter_length) ~= 1
    error('filter_length has to be a scalar')
end
% checking the value of filter length
if filter_length < 1 || isnan(filter_length) || ~isnumeric(filter_length)
   error('filter_length must be positive scalar and greater than zero')
end
end