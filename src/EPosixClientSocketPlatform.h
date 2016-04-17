#ifndef eposixclientsocketcommon_def
#define eposixclientsocketcommon_def

#ifdef _WIN32
	// Windows
	// includes
	#include <WinSock2.h>
	#include <time.h>

	// defines
	#define EISCONN WSAEISCONN
	#define EWOULDBLOCK WSAEWOULDBLOCK
	#define ECONNREFUSED WSAECONNREFUSED

	// helpers
	inline bool SocketsInit( void) {
#ifdef IB_NO_WSADATA
		/// @bug RPW workaround an issue where wsacleanup is called multiple times
		return true;
#else
		WSADATA data;
		return ( !WSAStartup( MAKEWORD(2, 2), &data));
#endif
	};
	inline bool SocketsDestroy() {
#ifdef IB_NO_WSADATA
		/// @bug RPW workaround an issue where wsacleanup is called multiple times
		return true;
#else
		return ( !WSACleanup());
#endif
	};
	inline int SocketClose(int sockfd) { return closesocket( sockfd); };

#else
	// LINUX
	// includes
	#include <arpa/inet.h>
	#include <errno.h>
	#include <sys/select.h>

	// helpers
	inline bool SocketsInit() { return true; };
	inline bool SocketsDestroy() { return true; };
	inline int SocketClose(int sockfd) { return close( sockfd); };

#endif

#endif
