%read in the two different images.
banana = imread('banana.jpg');
%we have the two images, now work with them to create altered versions of
%the images that we can analyze
%pass the image into the function, and begin to analyze the data.
%we now have a function that does itterative kmeans (10 itterations), 
% given an image. now run the function on both images.
kMeans(banana);


function kMeans(image)
    %go through the given image, 
    form = makecform('srgb2lab');
    alteredImgL = applycform(image,form);
    %alter it to obtain the data in double format
    imgData = double(alteredImgL(:,:,2:3));
    %find the number of rows and columns
    numRows = size(imgData,1);
    numCols = size(imgData,2);
    %reshape the data into a single vector/array
    imgData = reshape(imgData,numRows*numCols,2);

    k = 3;
    %we have k, now we need to run kmeans through iterations.
    kMeansVectorLength = size(imgData,1);
    %first create a way to store the data; each kmeans is a kMeansVetorLengthX1 matrix.
    %we need to store these in a 1XItterationLength sized matrix
    results = zeros(kMeansVectorLength, k); 

    data = kmeans(imgData,k); %perform kmeans, and keep it in a tmp var
        for j=1:kMeansVectorLength %go through all the pixels of the image/vector
            for x=1:k %for each pixel, go through all potential k
                if data(j,1) == x %if at correct k
                    results(j,x) = results(j,x) +1; %add 1 to the current k
                else
                    results(j,x) = results(j,x); %do nothing
                end %end comparison if chek
            end %end pixel examination
        end%end current image itteration being looked at
    %print out the data in three different maps for each k value.
    for count=1:k
       % alter the data to make the image from the vector
       reshapeMaps = reshape(results(:,count),numRows,numCols);
       %print out this image after the next (using count)
       subplot(floor(k/2) +2,floor(k/2),count), imshow(reshapeMaps,[]);
    end%end the for print loop
end%end the function
