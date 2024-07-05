function [idx] = binarySearch(vert,data)

n = length(vert);

if ~issorted(vert)
    idx = -2;
    return
end

[idx] = binarySearchRecursive(vert,data,1,n);

end