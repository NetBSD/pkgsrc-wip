$NetBSD$

Socket functions generally expect sockaddr, not sockaddr_in 
Check for presence of SIOCGIFHWADDR
Cast sockaddr to sockaddr_in properly before using it with syslog()

--- in.mvp/in.mvp.c.orig	2011-01-13 15:53:56.000000000 +0000
+++ in.mvp/in.mvp.c
@@ -77,7 +77,7 @@ static int c_gui_port = 5906;
 static int c_stream_port = 6337;
 static uint32_t c_vdr_host = 0x7f000001;
 
-static struct sockaddr_in from;
+static struct sockaddr from;
 static int fromlen;
 
 static int udp_send(char *data, int len, const char *addr, int port);
@@ -126,6 +126,7 @@ char* get_mac_address(char* ipaddr) {
             if (strcmp(ipaddr,inet_ntoa(((struct sockaddr_in *)&ifreq.ifr_addr)->sin_addr)) ){
                 continue;
             }
+#if defined(ifr_hwaddr)
             if (ioctl (s, SIOCGIFHWADDR, &ifreq) < 0) {
                 #ifdef LOGGING
                 syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_ERR), "SIOCGIFHWADDR(%s): %m\n", ifreq.ifr_name);
@@ -146,6 +147,7 @@ char* get_mac_address(char* ipaddr) {
             memcpy(mac_address,ifreq.ifr_hwaddr.sa_data,6);
             is_mac=1;
             break;
+#endif
         }
     }
     close(s);
@@ -232,13 +234,25 @@ main(int argc, char **argv) {
         memcpy(&in,&desthostip,4);
         desthost = inet_ntoa(in);
         #ifdef ONELOG
-        syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_NOTICE), "MVPOUT dest=%s, tftp=%s", inet_ntoa(from.sin_addr), argv[1]);
+	{
+		struct sockaddr_in *ipv4 = (struct sockaddr_in *)&from;
+		char ipv4str[INET_ADDRSTRLEN];
+
+		inet_ntop(AF_INET, &ipv4->sin_addr, ipv4str, INET_ADDRSTRLEN);
+		syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_NOTICE),
+		    "MVPOUT dest=%s, tftp=%s", ipv4str, argv[1]);
+	}
         #endif
         udp_send(data,52, desthost, destport);
     }
     else {
         #ifdef ONELOG
-        syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_ERR), "MVPERR size=%d, host=%s", len, inet_ntoa(from.sin_addr));
+	    struct sockaddr_in *ipv4 = (struct sockaddr_in *)&from;
+	    char ipv4str[INET_ADDRSTRLEN];
+
+	    inet_ntop(AF_INET, &ipv4->sin_addr, ipv4str, INET_ADDRSTRLEN);
+	    syslog(LOG_MAKEPRI(LOG_DAEMON, LOG_ERR), "MVPERR size=%d, host=%s",
+		len, ipv4str);
         #endif
     }
 
