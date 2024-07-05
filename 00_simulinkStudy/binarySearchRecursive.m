function [idx] = binarySearchRecursive(vert,data, l, h)
if h < 1
    idx = -1;
    return
end

key = floor((l+h)/2);

if vert(key) == data
    idx = key;
    return
end

if vert(key) < data %작으면?
    [idx] = binarySearchRecursive(vert,data,key+1,h);
else
    [idx] = binarySearchRecursive(vert,data,l,key-1);
end
end


