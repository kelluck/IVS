%%switch문
% a = 3;    
% switch a
%     case 1
%         disp("a는 1");
%     case 2
%         disp("a는 2");
%     case 3
%         disp("a는 3");
%     otherwise
%         disp("other value");
% end
% 

%%for문
% A = [1,2,3;4,5,6;7,8,9];
% for i = A
%     i
% end

%%while문
% i=0;
% while(i < 5)
%     i = i+1;
% end

%%function
% a = 3; b = 4;
% [c, d] = add(a,b);

% %sort
% vert = 100 : -1 : 1;
% [sorted] = Mysort(vert);

%%행렬
% M=1:100; % 1~100까지 열벡터
% N=reshape(M,4,25); %4행 25열 행렬로 변환
% T = N(2:3, 16:20)
% T2 = N(20:25)

% % NN = N' %전치행렬
% N = randi(100, 5, 5) %max값 100, 5x5행렬로 랜덤값
% T3 = sort(N,1) % 1은 열끼리 정렬
% T4 = sort(N,2) % 2는 행끼리 정렬
% T5 = sort(N) % 1이 default -> 열끼리 정렬

% %binarySearch
% vert = 1:2:100;
% ind = binarySearch(vert,33);

% %% 그림을 그리는 함수
% fig = figure(1);
% ax = axes(fig);
% limbox = [0,100];
% 
% xlim(ax,limbox);
% ylim(ax,limbox);
% hold on;
% 
% XData = [];
% YData = [];
% l1 = line(ax,[0,0], [0,0], "LineWidth", 2.0);
% 
% while 1
%     [x,y] = ginput(1);
%     if (limbox(1)>x) || (limbox(1)>y) || (limbox(2)<x) || (limbox(2)<y)
%         break
%     end
%     XData(end+1) = x;
%     YData(end+1) = y;
%     set(l1,"XData",XData,"YData",YData);
% end
% 
% XData = [XData,XData(1)];
% YData = [YData,YData(1)];