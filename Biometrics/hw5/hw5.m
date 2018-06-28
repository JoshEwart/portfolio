imageAnalysis('fingerPrint1.jpg');
imageAnalysis('fingerPrint2.jpg');

function imageAnalysis(originFP)%read in the image
    img = imread(originFP);
    %image already black and white,
    %turn into binary
    binaryFP = im2bw(img);
    %thin image
    %bwmorph example found at
    %https://www.mathworks.com/matlabcentral/fileexchange/31926-fingerprint-minutiae-extraction?focused=5190983&tab=function&s_tid=gn_loc_drop
    %(along with minutiae extraction
    %also used https://www.mathworks.com/help/images/ref/bwmorph.html#bui7adf-1-operation
    %for removal of problems with 'thin'
    %binaryFP is set to endpoints later,but is already defined.
    tempThin = ~bwmorph(binaryFP,'thin', 3);
    tempEndpoints = ~bwmorph(tempThin, 'endpoints', Inf);
    thinedFP = bwmorph(binaryFP-tempEndpoints,'thin', Inf);
    
    
    cleanBinaryFP = bwmorph(binaryFP,'clean',Inf);
    
    endPoints = bwmorph(cleanBinaryFP, 'endpoints', Inf);
    branchPoints = bwmorph(thinedFP, 'branchpoints', 1);
    [y,x] = find(endPoints);
    [y1,x1] = find(branchPoints);
    figure('Name', originFP, 'NumberTitle','on'),
    imshow(binaryFP);
    figure('Name', originFP,'NumberTitle','on'),
    imshow(thinedFP),
    hold on
    plot(x,y,'ro');
    plot(x1,y1,'bo');
    hold off
end