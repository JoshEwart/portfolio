%create distance vector
handDistance = zeros(5,14);
%hand1
[hand1X, hand1Y, handDistance(1,:)] = handLines('hand1.jpg');
%hand2
[hand2X, hand2Y, handDistance(2,:)] = handLines('hand2.jpg');
%hand3
[hand3X, hand3Y, handDistance(3,:)] = handLines('hand3.jpg');
%hand4
[hand4X, hand4Y, handDistance(4,:)] = handLines('hand4.jpg');
%hand5
[hand5X, hand5Y, handDistance(5,:)] = handLines('hand5.jpg');

%average distances!
averageDistance = sum(handDistance,1)/5;
disp(averageDistance);
%show all hands, with given distances
drawHands(hand1X,hand1Y,'hand1.jpg', 1);
drawHands(hand2X,hand2Y,'hand2.jpg', 2);
drawHands(hand3X,hand3Y,'hand3.jpg', 3);
drawHands(hand4X,hand4Y,'hand4.jpg', 4);
drawHands(hand5X,hand5Y,'hand5.jpg', 5);
%now, we want to show all hands, but with the overlay of the averaged hand.
%1. compute the average hand
avgX = (hand1X +hand2X +hand3X +hand4X +hand5X)/5;
avgY = (hand1Y +hand2Y +hand3Y +hand4Y +hand5Y)/5;
%show it overlapping each hand
drawHands(avgX, avgY, 'hand1.jpg', 11);
drawHands(avgX, avgY, 'hand2.jpg', 12);
drawHands(avgX, avgY, 'hand3.jpg', 13);
drawHands(avgX, avgY, 'hand4.jpg', 14);
drawHands(avgX, avgY, 'hand5.jpg', 15);

function drawHands(xLines, yLines, hand, number)
    figure(number); 
    %show the image
    img = imread(hand);
    greyhand = rgb2gray(img);
    imshow(greyhand);
    hold on
    for i=1:14
        plot(xLines(i,:),yLines(i,:), 'g');
    end
end


function [xlines, ylines, handDistance] = handLines(img)
    %read in the two different images.
    hand = imread(img);
    %go through the given image

    %we have the images,  we need to create a grayscale version to work with.
    greyhand = rgb2gray(hand);
    imshow(greyhand);

    imgData = zeros(28,1);

    imgData = ginput(28);

    xLines = zeros(14,100);
    yLines = zeros(14,100);

    distance = zeros(1,14);
    
    
    for i= 1:14
        if i==1
            j = i+1;
            xLines(i,:) = linspace(imgData(i,1), imgData(j,1));
            yLines(i,:) = linspace(imgData(i,2), imgData(j,2));
            j=j+1;
            
            %distance
            distance(i) = sqrt(((imgData(i,1) - imgData(j,1))^2)+(imgData(i,2)-imgData(j,2))^2);
           
        else
            xLines(i,:) = linspace(imgData(j,1), imgData(j+1,1));
            yLines(i,:) = linspace(imgData(j,2), imgData(j+1,2));
            
            %distance
            distance(i) = sqrt(((imgData(j,1) - imgData(j+1,1))^2)+(imgData(j,2)-imgData(j+1,2))^2);
     
            
            j = j+2;
        end
      
    end

    xlines =  xLines;
    ylines = yLines;
    handDistance = distance;
end

