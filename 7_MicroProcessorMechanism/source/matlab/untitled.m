% 시리얼 포트 설정
portName = 'COM6'; % 사용할 COM 포트
baudRate = 115200; % 보드레이트

% 시리얼 포트 객체 생성
s = serialport(portName, baudRate);

% 수신된 데이터 처리 함수
configureCallback(s, "terminator", @readData);

disp('데이터 수신 시작...');

% 무한 루프를 사용하여 데이터를 지속적으로 수신
while true
    pause(0.1); % 잠시 대기하여 다른 작업을 수행할 수 있도록 함
end

% 데이터 수신 및 출력 함수
function readData(src, ~)
    % 시리얼 포트에서 데이터를 읽음
    data = readline(src);
    
    % 수신된 데이터를 숫자로 변환
    numericData = str2double(data);
    
    % 변환된 데이터 출력
    if isnan(numericData)
        disp(['수신된 데이터: "', data, '" (숫자로 변환 불가)']);
    else
        disp(['수신된 숫자 데이터: ', num2str(numericData)]);
    end
end
