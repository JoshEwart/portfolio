%read in the pictures
imgBanana = imread('banana.jpg');
%we have the images,  we need to create a grayscale version to work with.
greyBanana = rgb2gray(imgBanana);
DensityScan(greyBanana);
%we have gray scale, now run clustering algorithm on it.
function DensityScan(image)
    imgData = double(image);
    %find the number of rows and columns
    numRows = size(imgData,1);
    numCols = size(imgData,2);
    %reshape the data into a single vector/array
    
    imgData = reshape(imgData,numRows*numCols,[]);
    
   
    imgSize = size(imgData,1);
    clusters = zeros(imgSize,1);
    %1 for black/background
    %2 for shades of grey
    %3 for white
    data = kmeans(imgData(:), 3);
    %show data
    newImg = reshape(data(:),numRows,numCols);
    imshow(newImg);
    
end