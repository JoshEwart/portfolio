%{
[UGR/GR:]
1. Use an existing video, or capture a new appropriate video (upper body, head and shoulders, natural/realistic movements). Perform a few shoulder shrugging events at different "intensities". You may want to consider a video with smooth background for easier processing.
^^^
%https://www.mathworks.com/help/matlab/ref/videoreader.html
videoUsage:^^^
%}

dataVideo = vision.VideoFileReader('headShoulders.mp4');


%{
2. Track the head position (bounding box or blob) using either tracking-by-prediction 
or tracking-by-detection (the Viola-Jones method)
^^^
https://www.mathworks.com/help/vision/ref/vision.cascadeobjectdetector-system-object.html
VideoTrack:^^^

https://www.mathworks.com/matlabcentral/answers/127164-detecting-face-very-fast-from-video-using-vision-cascadeobjectdetector-in-matlab-code
%}
%I couldn't determine how to get the line from the bounding box due to
%being unable to access the data of the frame in a way to get the intensity
%differences. If I had been able to get that data, I would have been able
%to get the lines. As for plotting, the following data Structue stores all
%head locations (left and right are easy to observe in the coded loop below
tempVideo = VideoReader('headShoulders.mp4');
tempFrames = read(tempVideo);
totalFrames = size(tempFrames,4);
time = linspace(0,totalFrames);
headLocation = zeros(totalFrames, 4);
k = 0;
videoWrite = vision.VideoFileWriter('processedDetect.avi','FrameRate',dataVideo.info.VideoFrameRate);
while k<totalFrames
    k=k+1;
    frame = step(dataVideo);
    %getFace
    facialDetection = vision.CascadeObjectDetector();
    videoDisplay = step(facialDetection, frame);
    %videoDisplay
    figure(1),imshow(frame);
    %show current frame
    %now write the facial detection overlay
    for i = 1:size(videoDisplay,1)
        rectangle('Position',videoDisplay(i,:),'LineWidth',3, 'lineStyle','-','EdgeColor', 'r');
    end
    [x y z] = size(frame);
    %LeftShoulderBox
    LBoundBox = [0 videoDisplay(2)+videoDisplay(4)-50 videoDisplay(1)+50 videoDisplay(4)/2];
    rectangle('Position',LBoundBox,'LineWidth',3, 'lineStyle','-','EdgeColor', 'b');
    %rightShoulder Box
    RBoundBox = [videoDisplay(1)+videoDisplay(3)-50 videoDisplay(2)+videoDisplay(4)-50 x  videoDisplay(4)/2];
    rectangle('Position',RBoundBox,'LineWidth',3, 'lineStyle','-','EdgeColor', 'b');
    %Output Img of Figure to frame
    curFrame = getframe(gcf);
    curImg = frame2im(curFrame);
    step(videoWrite,curImg);
    
    %plot head position vs time
    headLocation(k,:) = videoDisplay(i);
    
end
%implay(video);
release(videoWrite);

%make plot of the cordinates of the box, ignoring the height and width
time = linspace(0,totalFrames);
figure(2),plot(time, headLocation(:,1))
%results said that time and headLocation were different sizes, though set
%as the same size.Thus, plot file not included.
%{
3. Track shoulder lines as either (a) each shoulder independently, (b) both shoulders with two lines, or (c) both shoulders with a single line. Your choice should be towards increased robustness.
%}


%{
4. Detect shoulder shrugging.
Output:
Plots of (time, head position), (time, left shoulder position), (time, right shoulder position) 
Video of output (head and shoulder locations superimposed on each frame) with indications of when shrugging occurs.
%}




