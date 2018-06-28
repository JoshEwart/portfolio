%(i) image preprocessing: you may want to enhance the image (contrast);
%completed image preprocessing, updated image used
teethPic = imread('teeth_sample.png');
imshow(teethPic);
horizontalLine = horizonSplit(teethPic);
%have the y value where the image needs to be seperated, make two images
topImg = teethPic(1:horizontalLine,:,:);
bottomImg = teethPic(horizontalLine+1:end,:,:);
%we now have two images. for each, we want to find splitLines for each
%tooth
upperSplits(topImg);
lowerSplits(bottomImg);



%(ii) extract the bounding boxes/tetrahedra for all teeth in the field of view, using the method in [1]; 
%(iii) using the approximations from step (ii), estimate the outline of at least two teeth using the method in [1,2];
function [yMax] = horizonSplit(teethPic)
    %have img, need to be given the row to use.
    avgRows = zeros(size(teethPic, 1),1);
    for i=1:size(teethPic,1)
       avgRows(i,:) = mean(teethPic(i,:));%get average of each row
    end
    %we now have the average for each y, we want to find the y that has the
    %greatest local min.
    localMinSpots = islocalmin(avgRows);
    depthValues = avgRows(localMinSpots);%get the depth Values (D)
    maxDepthVal = max(depthValues(:));
    
    %Probability of D
    probabilityD = zeros(size(depthValues,1));
    
    for i=1:size(depthValues,1)
        probabilityD(i) = 1 - (depthValues(i)/maxDepthVal);
    end
    disp(probabilityD);
    %Probability of Y
    %get Manually set Point
    imshow(teethPic);
    temp = ginput(1);
    userY = temp(2);
    
    yValues = 1:472;%get the position Values (y)
    yValues = yValues(localMinSpots);
    standardDev = std(yValues);
    probabilityY = zeros(size(yValues,1));
    for i=1:size(yValues,2)
        a = 1/((sqrt(2*pi))* standardDev);
        b = exp(-((yValues(i)-userY)^2)/((standardDev)^2));
        probabilityY(i) = a*b;
    end
    
    disp(probabilityY);
    %get probability of P(D) * P(Y)
    probabilityTotal = zeros(size(yValues,1));
    for i=1:size(yValues,2)
       probabilityTotal(i) = probabilityY(i) * probabilityD(i);
    end
    
    disp(probabilityTotal);
    %get max probability, and index
    [maxProbability, indexMax] = max(probabilityTotal);
    
    yMax = yValues(indexMax);
    disp(yMax);
    figure(1),imshow(teethPic);
    hold on
    figure(1),plot([1 512],[yMax,yMax],'red');
    hold off
end



function upperSplits(topImg)
    %we need to split the teeth
     %have img, need to be given the columns' avg to use.
    avgCols = zeros(size(topImg, 1), 1);
    for i=1:size(topImg,1)
       avgCols(i,:) = mean(topImg(i,:));%get average of each column
    end
    %we now have the average for each x, we want to find the x that has the
    %greatest local mins.
    localMinSpots = islocalmin(avgCols);
    depthValues = avgCols(localMinSpots);%get the depth Values (D)
    maxDepthVal = max(depthValues);
    
    %Probability of D
    probabilityD = zeros(size(depthValues, 1));
    for i=1:size(depthValues,1)
        probabilityD(i) = 1 - (depthValues(i)/maxDepthVal);
    end
    
    %Probability of Y
    %get Manually set Points for each teeth
    figure(2),imshow(topImg);
    userX = ginput(4);
    
    xValues = 1:512;%get the position Values (x)
    xValues = xValues(localMinSpots);
    standardDev = std(xValues);
    probabilityX = zeros(size(xValues,1));
    
    %create array for all points
    xCols = zeros(4,1);
    %now we need to find probabilityX for each userX
   
    
    for allX=1:4
        for i=1:size(xValues,2)
            a = 1/((sqrt(2*pi))* standardDev);
            b = exp(-((xValues(1,i)-userX(allX,1))^2)/((standardDev)^2));
            probabilityX(i) = a*b;
        end
        %get probability of P(D) * P(Y)
        probabilityTotal = zeros(size(xValues,2));
        for i=1:size(xValues,2)
           probabilityTotal(i) = probabilityX(i) * probabilityD(i);
        end
        
        disp(allX);
        
        %get max probability, and index
        [maxProbability, xPosition] = max(probabilityTotal(:));
        %disp(xCols(allX));
        xCols(allX) = xPosition;
        disp(xCols(allX));
        hold on
        figure(2),plot([xCols(allX),xCols(allX)], [1, size(topImg,1)],'red');
        hold off
    end
    
end




function lowerSplits(bottomImg)
    %we need to split the teeth
     %have img, need to be given the columns' avg to use.
    avgCols = zeros(size(bottomImg, 1), 1);
    for i=1:size(bottomImg,1)
       avgCols(i,:) = mean(bottomImg(i,:));%get average of each column
    end
    %we now have the average for each x, we want to find the x that has the
    %greatest local mins.
    localMinSpots = islocalmin(avgCols);
    depthValues = avgCols(localMinSpots);%get the depth Values (D)
    maxDepthVal = max(depthValues);
    
    %Probability of D
    probabilityD = zeros(size(depthValues, 1));
    for i=1:size(depthValues,1)
        probabilityD(i) = 1 - (depthValues(i)/maxDepthVal);
    end
    
    %Probability of Y
    %get Manually set Points for each teeth
    figure(3),imshow(bottomImg);
    userX = ginput(4);
    
    xValues = 1:512;%get the position Values (x)
    xValues = xValues(localMinSpots);
    standardDev = std(xValues);
    probabilityX = zeros(size(xValues,1));
    
    %create array for all points
    xCols = zeros(4,1);
    %now we need to find probabilityX for each userX
   
    
    for allX=1:4
        for i=1:size(xValues,2)
            a = 1/((sqrt(2*pi))* standardDev);
            b = exp(-((xValues(1,i)-userX(allX,1))^2)/((standardDev)^2));
            probabilityX(i) = a*b;
        end
        %get probability of P(D) * P(Y)
        probabilityTotal = zeros(size(xValues,2));
        for i=1:size(xValues,2)
           probabilityTotal(i) = probabilityX(i) * probabilityD(i);
        end
        
        
        disp(allX);
        
        %get max probability, and index
        [maxProbability, xPosition] = max(probabilityTotal(:));

        xCols(allX) = xPosition;
        disp(xCols(allX));
        hold on
        figure(3),plot([xCols(allX),xCols(allX)], [1, size(bottomImg,1)],'red');
        hold off
    end
    

end