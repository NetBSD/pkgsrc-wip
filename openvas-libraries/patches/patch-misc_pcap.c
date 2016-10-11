$NetBSD$

--- misc/pcap.c.orig	2015-08-03 10:14:29.000000000 +0000
+++ misc/pcap.c
@@ -126,7 +126,13 @@ v6_is_local_ip (struct in6_addr *addr)
           bpf_u_int32 net, mask;
           char errbuf[PCAP_ERRBUF_SIZE];
           pcap_lookupnet (ifs[i].name, &net, &mask, errbuf);
+#if defined(__NetBSD__)
+          uint32_t addr32;
+          memcpy(&addr32, &addr->s6_addr[12], 4);
+          if ((net & mask) == (addr32 & mask))
+#else
           if ((net & mask) == (addr->s6_addr32[3] & mask))
+#endif
             return 1;
         }
     }
@@ -190,9 +196,17 @@ v6_get_mac_addr (struct in6_addr *addr, 
       if (soc < 0)
         return -1;
 
+#if defined(__NetBSD__)
+      memcpy(&inaddr.s_addr, &me.s6_addr[12], 4);
+#else
       inaddr.s_addr = me.s6_addr32[3];
+#endif
       src_host = g_strdup (inet_ntoa (inaddr));
+#if defined(__NetBSD__)
+      memcpy(&inaddr.s_addr, &addr->s6_addr[12], 4);
+#else
       inaddr.s_addr = addr->s6_addr32[3];
+#endif
       dst_host = g_strdup (inet_ntoa (inaddr));
       snprintf (filter, sizeof (filter)-1, "ip and (src host %s and dst host %s)",
                 src_host, dst_host);
@@ -217,7 +231,11 @@ v6_get_mac_addr (struct in6_addr *addr, 
         }
 
 
+#if defined(__NetBSD__)
+      memcpy(&soca.sin_addr.s_addr, &addr->s6_addr[12], 4);
+#else
       soca.sin_addr.s_addr = addr->s6_addr32[3];
+#endif
       soca.sin_port = htons (9);        /* or whatever */
       soca.sin_family = AF_INET;
       if (sendto (soc, NULL, 0, 0, (struct sockaddr *) &soca, sizeof (soca)) !=
@@ -386,11 +404,21 @@ v6_islocalhost (struct in6_addr *addr)
     {
       /* If it is 0.0.0.0 or starts with 127.0.0.1 then it is
          probably localhost */
+#if defined(__NetBSD__)
+      uint32_t addr32;
+      memcpy(&addr32, &addr->s6_addr[12], 4);
+      if ((addr32 & htonl (0xFF000000)) == htonl (0x7F000000))
+        return 1;
+
+      if (!addr32)
+        return 1;
+#else
       if ((addr->s6_addr32[3] & htonl (0xFF000000)) == htonl (0x7F000000))
         return 1;
 
       if (!addr->s6_addr32[3])
         return 1;
+#endif
     }
 
   if (IN6_IS_ADDR_LOOPBACK (addr))
@@ -571,6 +599,37 @@ v6_getinterfaces (int *howmany)
               memcpy (mydevs[numinterfaces].name, ifa->ifa_name,
                       strlen (ifa->ifa_name));
               saddr = (struct sockaddr_in *) ifa->ifa_addr;
+#if defined(__NetBSD__)
+              mydevs[numinterfaces].addr6.s6_addr[0] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[1] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[2] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[3] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[4] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[5] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[6] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[7] = 0;
+              // TODO: Big endian
+              mydevs[numinterfaces].addr6.s6_addr[8] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[9] = 0;
+              mydevs[numinterfaces].addr6.s6_addr[10] = 0xff;
+              mydevs[numinterfaces].addr6.s6_addr[11] = 0xff;
+              memcpy (&mydevs[numinterfaces].addr6.s6_addr[12], &saddr->sin_addr.s_addr, 4);
+              saddr = (struct sockaddr_in *) ifa->ifa_netmask;
+              mydevs[numinterfaces].mask.s6_addr[0] = 0;
+              mydevs[numinterfaces].mask.s6_addr[1] = 0;
+              mydevs[numinterfaces].mask.s6_addr[2] = 0;
+              mydevs[numinterfaces].mask.s6_addr[3] = 0;
+              mydevs[numinterfaces].mask.s6_addr[4] = 0;
+              mydevs[numinterfaces].mask.s6_addr[5] = 0;
+              mydevs[numinterfaces].mask.s6_addr[6] = 0;
+              mydevs[numinterfaces].mask.s6_addr[7] = 0;
+              // TODO: Big endian
+              mydevs[numinterfaces].mask.s6_addr[8] = 0;
+              mydevs[numinterfaces].mask.s6_addr[9] = 0;
+              mydevs[numinterfaces].mask.s6_addr[10] = 0xff;
+              mydevs[numinterfaces].mask.s6_addr[11] = 0xff;
+              memcpy (&mydevs[numinterfaces].mask.s6_addr[12], &saddr->sin_addr.s_addr, 4);
+#else
               mydevs[numinterfaces].addr6.s6_addr32[0] = 0;
               mydevs[numinterfaces].addr6.s6_addr32[1] = 0;
               mydevs[numinterfaces].addr6.s6_addr32[2] = htonl (0xffff);
@@ -580,6 +639,7 @@ v6_getinterfaces (int *howmany)
               mydevs[numinterfaces].mask.s6_addr32[1] = 0;
               mydevs[numinterfaces].mask.s6_addr32[2] = htonl (0xffff);
               mydevs[numinterfaces].mask.s6_addr32[3] = saddr->sin_addr.s_addr;
+#endif
 #ifdef TCPIP_DEBUGGING
               printf ("interface name is %s\n", ifa->ifa_name);
               printf ("\tAF_INET family\n");
@@ -631,13 +691,19 @@ getinterfaces (int *howmany)
   static struct interface_info mydevs[1024];
   int numinterfaces = 0;
   int sd;
+#if defined(__NetBSD__)
+  size_t n;
+#else
   int len;
+#endif
   char *p;
   char buf[10240];
   struct ifconf ifc;
   struct ifreq *ifr;
   struct sockaddr_in *sin;
+#if !defined(__NetBSD__)
   char *bufp;
+#endif
 
   /* Dummy socket for ioctl. */
   sd = socket (AF_INET, SOCK_DGRAM, 0);
@@ -655,12 +721,18 @@ getinterfaces (int *howmany)
     log_legacy_write
      ("getinterfaces: SIOCGIFCONF claims you have no network interfaces!");
 
+#if defined(__NetBSD__)
+  for (ifr = (struct ifreq *) buf; (char *) ifr < buf + ifc.ifc_len; )
+#else
   len = sizeof (struct ifmap);
 
   for (bufp = buf; bufp && *bufp && (bufp < (buf + ifc.ifc_len));
        bufp += sizeof (ifr->ifr_name) + len)
+#endif
     {
+#if !defined(__NetBSD__)
       ifr = (struct ifreq *) bufp;
+#endif
       sin = (struct sockaddr_in *) &ifr->ifr_addr;
       memcpy (&(mydevs[numinterfaces].addr), (char *) &(sin->sin_addr),
               sizeof (struct in_addr));
@@ -670,6 +742,9 @@ getinterfaces (int *howmany)
       strncpy (mydevs[numinterfaces].name, ifr->ifr_name, 63);
       mydevs[numinterfaces].name[63] = '\0';
       numinterfaces++;
+#if defined(__NetBSD__)
+      mydevs[numinterfaces].name[0] = '\0';
+#endif
       if (numinterfaces == 1023)
         {
           log_legacy_write
@@ -677,7 +752,15 @@ getinterfaces (int *howmany)
             " Things may not work right.");
           break;
         }
+#if defined(__NetBSD__)
+      n = offsetof(struct ifreq, ifr_addr) + ifr->ifr_addr.sa_len;
+      if (n < sizeof(*ifr))
+          ifr++;
+      else
+          ifr = (struct ifreq *)((char *)ifr + n);
+#else
       mydevs[numinterfaces].name[0] = '\0';
+#endif
     }
 
   // If output parameter given, set value
@@ -712,7 +795,11 @@ v6_getsourceip (struct in6_addr *src, st
           return 0;
         }
       sock.sin_family = AF_INET;
+#if defined(__NetBSD__)
+      memcpy(&sock.sin_addr.s_addr, &dst->s6_addr[12], 4);
+#else
       sock.sin_addr.s_addr = dst->s6_addr32[3];
+#endif
       sock.sin_port = htons (p1);
       if (connect (sd, (struct sockaddr *) &sock, sizeof (struct sockaddr_in))
           == -1)
@@ -730,10 +817,27 @@ v6_getsourceip (struct in6_addr *src, st
         }
 
 
+#if defined(__NetBSD__)
+      src->s6_addr[0] = 0;
+      src->s6_addr[1] = 0;
+      src->s6_addr[2] = 0;
+      src->s6_addr[3] = 0;
+      src->s6_addr[4] = 0;
+      src->s6_addr[5] = 0;
+      src->s6_addr[6] = 0;
+      src->s6_addr[7] = 0;
+      // TODO: Big-endian
+      src->s6_addr[8] = 0;
+      src->s6_addr[9] = 0;
+      src->s6_addr[10] = 0xff;
+      src->s6_addr[11] = 0xff;
+      memcpy (&src->s6_addr[12], &sock.sin_addr.s_addr, 4);
+#else
       src->s6_addr32[0] = 0;
       src->s6_addr32[1] = 0;
       src->s6_addr32[2] = htonl (0xffff);
       src->s6_addr32[3] = sock.sin_addr.s_addr;
+#endif
 #ifdef TCPIP_DEBUGGING
       printf ("source addrss is %s\n",
               inet_ntop (AF_INET6, src, name, sizeof (name)));
@@ -748,10 +852,16 @@ v6_getsourceip (struct in6_addr *src, st
           return 0;
         }
       sock6.sin6_family = AF_INET6;
+#if defined(__NetBSD__)
+      size_t iter;
+      for (iter = 0; iter < 16; iter++)
+        sock6.sin6_addr.s6_addr[iter] = dst->s6_addr[iter];
+#else
       sock6.sin6_addr.s6_addr32[0] = dst->s6_addr32[0];
       sock6.sin6_addr.s6_addr32[1] = dst->s6_addr32[1];
       sock6.sin6_addr.s6_addr32[2] = dst->s6_addr32[2];
       sock6.sin6_addr.s6_addr32[3] = dst->s6_addr32[3];
+#endif
       sock6.sin6_port = htons (p1);
       if (connect (sd, (struct sockaddr *) &sock6, sizeof (struct sockaddr_in6))
           == -1)
@@ -768,10 +878,15 @@ v6_getsourceip (struct in6_addr *src, st
           return 0;
         }
 
+#if defined(__NetBSD__)
+      for (iter = 0; iter < 16; iter++)
+        src->s6_addr[iter] = sock6.sin6_addr.s6_addr[iter];
+#else
       src->s6_addr32[0] = sock6.sin6_addr.s6_addr32[0];
       src->s6_addr32[1] = sock6.sin6_addr.s6_addr32[1];
       src->s6_addr32[2] = sock6.sin6_addr.s6_addr32[2];
       src->s6_addr32[3] = sock6.sin6_addr.s6_addr32[3];
+#endif
       memcpy (src, &sock6.sin6_addr, sizeof (struct in6_addr));
 #ifdef TCPIP_DEBUGGING
       printf ("source addrss is %s\n",
@@ -880,10 +995,27 @@ getipv4routes (struct myroute *myroutes,
               continue;
             }
           inaddr.s_addr = dest;
+#if defined(__NetBSD__)
+          myroutes[*numroutes].dest6.s6_addr[0] = 0;
+          myroutes[*numroutes].dest6.s6_addr[1] = 0;
+          myroutes[*numroutes].dest6.s6_addr[2] = 0;
+          myroutes[*numroutes].dest6.s6_addr[3] = 0;
+          myroutes[*numroutes].dest6.s6_addr[4] = 0;
+          myroutes[*numroutes].dest6.s6_addr[5] = 0;
+          myroutes[*numroutes].dest6.s6_addr[6] = 0;
+          myroutes[*numroutes].dest6.s6_addr[7] = 0;
+          // TODO: Big-endian
+          myroutes[*numroutes].dest6.s6_addr[8] = 0;
+          myroutes[*numroutes].dest6.s6_addr[9] = 0;
+          myroutes[*numroutes].dest6.s6_addr[10] = 0xff;
+          myroutes[*numroutes].dest6.s6_addr[11] = 0xff;
+          memcpy (&myroutes[*numroutes].dest6.s6_addr[12], &inaddr.s_addr, 4);
+#else
           myroutes[*numroutes].dest6.s6_addr32[0] = 0;
           myroutes[*numroutes].dest6.s6_addr32[1] = 0;
           myroutes[*numroutes].dest6.s6_addr32[2] = htonl (0xffff);
           myroutes[*numroutes].dest6.s6_addr32[3] = inaddr.s_addr;
+#endif
           for (i = 0; i < 6; i++)
             {
               p = strtok (NULL, " \t\n");
@@ -1112,17 +1244,55 @@ v6_routethrough (struct in6_addr *dest, 
         {
           if (IN6_IS_ADDR_V4MAPPED (source))
             {
+#if defined(__NetBSD__)
+              source->s6_addr[0] = 0;
+              source->s6_addr[1] = 0;
+              source->s6_addr[2] = 0;
+              source->s6_addr[3] = 0;
+              source->s6_addr[4] = 0;
+              source->s6_addr[5] = 0;
+              source->s6_addr[6] = 0;
+              source->s6_addr[7] = 0;
+              source->s6_addr[8] = 0;
+              source->s6_addr[9] = 0;
+              source->s6_addr[10] = 0xff;
+              source->s6_addr[11] = 0xff;
+              source->s6_addr[12] = 0x7f;
+              source->s6_addr[13] = 0;
+              source->s6_addr[14] = 0;
+              source->s6_addr[15] = 1;
+#else
               source->s6_addr32[0] = 0;
               source->s6_addr32[1] = 0;
               source->s6_addr32[2] = htonl (0xffff);
               source->s6_addr32[3] = htonl (0x7F000001);
+#endif
             }
           else
             {
+#if defined(__NetBSD__)
+              source->s6_addr[0] = 0;
+              source->s6_addr[1] = 0;
+              source->s6_addr[2] = 0;
+              source->s6_addr[3] = 0;
+              source->s6_addr[4] = 0;
+              source->s6_addr[5] = 0;
+              source->s6_addr[6] = 0;
+              source->s6_addr[7] = 0;
+              source->s6_addr[8] = 0;
+              source->s6_addr[9] = 0;
+              source->s6_addr[10] = 0;
+              source->s6_addr[11] = 0;
+              source->s6_addr[12] = 0;
+              source->s6_addr[13] = 0;
+              source->s6_addr[14] = 0;
+              source->s6_addr[15] = 1;
+#else
               source->s6_addr32[0] = 0;
               source->s6_addr32[1] = 0;
               source->s6_addr32[2] = 0;
               source->s6_addr32[3] = htonl (1);
+#endif
             }
         }
       /* Now we find the localhost interface name, assuming 127.0.0.1
@@ -1131,7 +1301,13 @@ v6_routethrough (struct in6_addr *dest, 
         {
           if (IN6_IS_ADDR_V4MAPPED (&mydevs[i].addr6))
             {
+#if defined(__NetBSD__)
+              uint32_t addr32;
+              memcpy(&addr32, &mydevs[i].addr6.s6_addr[12], 4);
+              if (addr32 == htonl (0x7F000001))
+#else
               if (mydevs[i].addr6.s6_addr32[3] == htonl (0x7F000001))
+#endif
                 return mydevs[i].name;
             }
           else
@@ -1195,11 +1371,28 @@ v6_routethrough (struct in6_addr *dest, 
             log_legacy_write ("Cannot get hostname!");
           if (myhostent->h_addrtype == AF_INET)
             {
+#if defined(__NetBSD__)
+              addy.s6_addr[0] = 0;
+              addy.s6_addr[1] = 0;
+              addy.s6_addr[2] = 0;
+              addy.s6_addr[3] = 0;
+              addy.s6_addr[4] = 0;
+              addy.s6_addr[5] = 0;
+              addy.s6_addr[6] = 0;
+              addy.s6_addr[7] = 0;
+              addy.s6_addr[8] = 0;
+              addy.s6_addr[9] = 0;
+              addy.s6_addr[10] = 0xff;
+              addy.s6_addr[11] = 0xff;
+              memcpy (&addy.s6_addr[12], myhostent->h_addr_list[0],
+                      sizeof (struct in6_addr));
+#else
               addy.s6_addr32[0] = 0;
               addy.s6_addr32[1] = 0;
               addy.s6_addr32[2] = htonl (0xffff);
-              memcpy (&addy.s6_addr32[0], myhostent->h_addr_list[0],
+              memcpy (&addy.s6_addr32[0 /* bug? why not 3 */], myhostent->h_addr_list[0],
                       sizeof (struct in6_addr));
+#endif
             }
           else
             memcpy (&addy, myhostent->h_addr_list[0], sizeof (struct in6_addr));
