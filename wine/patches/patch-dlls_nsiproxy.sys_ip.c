$NetBSD$

NetBSD changed ICMP stats from a structure to an array of uint64_t's.

--- dlls/nsiproxy.sys/ip.c.orig	2022-01-07 21:03:02.000000000 +0000
+++ dlls/nsiproxy.sys/ip.c
@@ -302,12 +302,53 @@ static NTSTATUS ipv4_icmpstats_get_all_p
 #elif defined(HAVE_SYS_SYSCTL_H) && defined(ICMPCTL_STATS)
     {
         int mib[] = { CTL_NET, PF_INET, IPPROTO_ICMP, ICMPCTL_STATS };
+#if defined(__NetBSD__)
+        uint64_t icmp_stat[ICMP_NSTATS];
+#else
         struct icmpstat icmp_stat;
+#endif
         size_t needed = sizeof(icmp_stat);
         int i;
 
         if (sysctl( mib, ARRAY_SIZE(mib), &icmp_stat, &needed, NULL, 0 ) == -1) return STATUS_NOT_SUPPORTED;
 
+#if defined(__NetBSD__)
+        dyn.in_msgs = icmp_stat[ICMP_STAT_BADCODE] + icmp_stat[ICMP_STAT_CHECKSUM] + icmp_stat[ICMP_STAT_TOOSHORT] + icmp_stat[ICMP_STAT_BADLEN];
+        for (i = 0; i <= ICMP_MAXTYPE; i++)
+            dyn.in_msgs += icmp_stat[ICMP_STAT_INHIST + i];
+
+        dyn.in_errors = icmp_stat[ICMP_STAT_BADCODE] + icmp_stat[ICMP_STAT_TOOSHORT] + icmp_stat[ICMP_STAT_CHECKSUM] + icmp_stat[ICMP_STAT_BADLEN];
+
+        dyn.in_type_counts[ICMP4_DST_UNREACH] = icmp_stat[ICMP_STAT_INHIST + ICMP_UNREACH];
+        dyn.in_type_counts[ICMP4_TIME_EXCEEDED] = icmp_stat[ICMP_STAT_INHIST + ICMP_TIMXCEED];
+        dyn.in_type_counts[ICMP4_PARAM_PROB] = icmp_stat[ICMP_STAT_INHIST + ICMP_PARAMPROB];
+        dyn.in_type_counts[ICMP4_SOURCE_QUENCH] = icmp_stat[ICMP_STAT_INHIST + ICMP_SOURCEQUENCH];
+        dyn.in_type_counts[ICMP4_REDIRECT] = icmp_stat[ICMP_STAT_INHIST + ICMP_REDIRECT];
+        dyn.in_type_counts[ICMP4_ECHO_REQUEST] = icmp_stat[ICMP_STAT_INHIST + ICMP_ECHO];
+        dyn.in_type_counts[ICMP4_ECHO_REPLY] = icmp_stat[ICMP_STAT_INHIST + ICMP_ECHOREPLY];
+        dyn.in_type_counts[ICMP4_TIMESTAMP_REQUEST] = icmp_stat[ICMP_STAT_INHIST + ICMP_TSTAMP];
+        dyn.in_type_counts[ICMP4_TIMESTAMP_REPLY] = icmp_stat[ICMP_STAT_INHIST + ICMP_TSTAMPREPLY];
+        dyn.in_type_counts[ICMP4_MASK_REQUEST] = icmp_stat[ICMP_STAT_INHIST + ICMP_MASKREQ];
+        dyn.in_type_counts[ICMP4_MASK_REPLY] = icmp_stat[ICMP_STAT_INHIST + ICMP_MASKREPLY];
+
+        dyn.out_msgs = icmp_stat[ICMP_STAT_OLDSHORT] + icmp_stat[ICMP_STAT_OLDICMP];
+        for (i = 0; i <= ICMP_MAXTYPE; i++)
+            dyn.out_msgs += icmp_stat[ICMP_STAT_OUTHIST + i];
+
+        dyn.out_errors = icmp_stat[ICMP_STAT_OLDSHORT] + icmp_stat[ICMP_STAT_OLDICMP];
+
+        dyn.out_type_counts[ICMP4_DST_UNREACH] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_UNREACH];
+        dyn.out_type_counts[ICMP4_TIME_EXCEEDED] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_TIMXCEED];
+        dyn.out_type_counts[ICMP4_PARAM_PROB] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_PARAMPROB];
+        dyn.out_type_counts[ICMP4_SOURCE_QUENCH] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_SOURCEQUENCH];
+        dyn.out_type_counts[ICMP4_REDIRECT] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_REDIRECT];
+        dyn.out_type_counts[ICMP4_ECHO_REQUEST] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_ECHO];
+        dyn.out_type_counts[ICMP4_ECHO_REPLY] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_ECHOREPLY];
+        dyn.out_type_counts[ICMP4_TIMESTAMP_REQUEST] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_TSTAMP];
+        dyn.out_type_counts[ICMP4_TIMESTAMP_REPLY] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_TSTAMPREPLY];
+        dyn.out_type_counts[ICMP4_MASK_REQUEST] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_MASKREQ];
+        dyn.out_type_counts[ICMP4_MASK_REPLY] = icmp_stat[ICMP_STAT_OUTHIST + ICMP_MASKREPLY];
+#else
         dyn.in_msgs = icmp_stat.icps_badcode + icmp_stat.icps_checksum + icmp_stat.icps_tooshort + icmp_stat.icps_badlen;
         for (i = 0; i <= ICMP_MAXTYPE; i++)
             dyn.in_msgs += icmp_stat.icps_inhist[i];
@@ -343,6 +384,7 @@ static NTSTATUS ipv4_icmpstats_get_all_p
         dyn.out_type_counts[ICMP4_TIMESTAMP_REPLY] = icmp_stat.icps_outhist[ICMP_TSTAMPREPLY];
         dyn.out_type_counts[ICMP4_MASK_REQUEST] = icmp_stat.icps_outhist[ICMP_MASKREQ];
         dyn.out_type_counts[ICMP4_MASK_REPLY] = icmp_stat.icps_outhist[ICMP_MASKREPLY];
+#endif
         if (dynamic_data) *(struct nsi_ip_icmpstats_dynamic *)dynamic_data = dyn;
         return STATUS_SUCCESS;
     }
@@ -921,7 +963,11 @@ static NTSTATUS ipv4_neighbour_enumerate
     }
 #elif defined(HAVE_SYS_SYSCTL_H)
     {
+#if defined(__NetBSD__)
+        int mib[] = { CTL_NET, PF_ROUTE, 0, AF_INET, NET_RT_FLAGS }, sinarp_len;
+#else
         int mib[] = { CTL_NET, PF_ROUTE, 0, AF_INET, NET_RT_FLAGS, RTF_LLINFO }, sinarp_len;
+#endif
         size_t needed;
         char *buf = NULL, *lim, *next;
         struct rt_msghdr *rtm;
@@ -1143,7 +1189,9 @@ static NTSTATUS ipv4_forward_enumerate_a
             }
 
             /* Ignore gateway routes which are multicast */
+#if !defined(__NetBSD__)
             if ((rtm->rtm_flags & RTF_GATEWAY) && (rtm->rtm_flags & RTF_MULTICAST)) continue;
+#endif
 
             entry.if_index = rtm->rtm_index;
             if (!convert_index_to_luid( entry.if_index, &entry.luid )) continue;
