#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>

using namespace std;

int main()//            SERVER
{
    WSADATA wsData;
    WSAStartup(MAKEWORD(2,2), &wsData);

    cout << "Server ready" << endl;

    SOCKET servSocket;
    servSocket = socket(AF_INET, SOCK_STREAM, 0);

    //in_addr ip2num;
    //InetPtonW(AF_INET, "127.0.0.1", &ip2num);

    struct sockaddr_in servInfo;
    memset(&servInfo, 0, sizeof(servInfo));
    servInfo.sin_family = AF_INET;
    servInfo.sin_port = htons(1111);
    servInfo.sin_addr.s_addr = inet_addr("90.154.72.132");

    bind(servSocket, (struct sockaddr *)&servInfo, sizeof(servInfo));
    listen(servSocket, 10);

    int buf[5];
    memset(buf, 0, sizeof(buf));

    SOCKET clientSocket;
    clientSocket = accept(servSocket, NULL, NULL);

    cout << "Connect OK" << endl;
    while(recv(clientSocket, (char*)buf, sizeof(buf), 0) > 0)
    {
        system("rundll32.exe user32.dll, LockWorkStation");
    }
    closesocket(servSocket);


    return 0;
    //system("rundll32.exe user32.dll, LockWorkStation");
}
