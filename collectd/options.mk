# $NetBSD: options.mk,v 1.3 2010/06/20 11:53:07 thomasklausner Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=		rrdtool libstatgrab curl debug apache
PKG_SUPPORTED_OPTIONS+=		apcups ascent bind cpu csv dbi df
PKG_SUPPORTED_OPTIONS+=		disk dns email exec filecount
PKG_SUPPORTED_OPTIONS+=		interface load logfile
PKG_SUPPORTED_OPTIONS+=		match_empty_counter match_hashed match_regex
PKG_SUPPORTED_OPTIONS+=		match_timediff match_value mbmon memcachec
PKG_SUPPORTED_OPTIONS+=		memcached memory multimeter mysql
PKG_SUPPORTED_OPTIONS+=		network nginx notify_desktop notify_email ntpd
PKG_SUPPORTED_OPTIONS+=		olsrd openvpn perl postgresql
PKG_SUPPORTED_OPTIONS+=		powerdns python
PKG_SUPPORTED_OPTIONS+=		snmp swap syslog table tail
PKG_SUPPORTED_OPTIONS+=		target_notification target_replace target_scale
PKG_SUPPORTED_OPTIONS+=		target_set tcpconns teamspeak2 ted
PKG_SUPPORTED_OPTIONS+=		unixsock uptime users uuid write_http

PKG_SUGGESTED_OPTIONS+=		rrdtool curl libstatgrab
.include "../../mk/bsd.options.mk"

#rrdtool
.if !empty(PKG_OPTIONS:Mrrdtool)
.include "../../databases/rrdtool/buildlink3.mk"
#CONFIGURE_ARGS+=    --with-librrd=${BUILDLINK_PREFIX.rrdtool}
CONFIGURE_ARGS+=	--enable-rrdtool
PLIST.rrdtool=	yes
.endif

#curl
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--enable-curl
PLIST.curl=	yes
.endif

#libstatgrab
.if !empty(PKG_OPTIONS:Mlibstatgrab)
.include "../../devel/libstatgrab/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libstatgrab=${BUILDLINK_PREFIX.libstatgraph}
PLIST.hddtemp=	yes
.endif

#snmp
.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-libsnmp=${BUILDLINK_PREFIX.net-snmp}
CONFIGURE_ARGS+=	--enable-snmp
PLIST.snmp=	yes
.endif

#debug
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mapache)
.include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-apache
PLIST.apache=	yes
.else
CONFIGURE_ARGS+=	--disable-apache
.endif

.if !empty(PKG_OPTIONS:Mapcups)
CONFIGURE_ARGS+=	--enable-apcups
PLIST.apcups=	yes
.else
CONFIGURE_ARGS+=	--disable-apcups
.endif

.if !empty(PKG_OPTIONS:Mascent)
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ascent
PLIST.ascent=	yes
.else
CONFIGURE_ARGS+=	--disable-ascent
.endif


.if !empty(PKG_OPTIONS:Mbind)
.include "../../net/libpcap/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-bind
PLIST.bind=	yes
.else
CONFIGURE_ARGS+=	--disable-bind
.endif

.if !empty(PKG_OPTIONS:Mcpu)
CONFIGURE_ARGS+=	--enable-cpu
PLIST.cpu=	yes
.else
CONFIGURE_ARGS+=	--disable-cpu
.endif

.if !empty(PKG_OPTIONS:Mcsv)
CONFIGURE_ARGS+=	--enable-csv
PLIST.csv=	yes
.else
CONFIGURE_ARGS+=	--disable-csv
.endif

.if !empty(PKG_OPTIONS:Mdbi)
#CONFIGURE_ARGS+=	--with-libdbi=${BUILDLINK_PREFIX.libdbi}
.include "../../databases/libdbi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbi
PLIST.dbi=	yes
.else
CONFIGURE_ARGS+=	--disable-dbi
.endif

.if !empty(PKG_OPTIONS:Mdf)
CONFIGURE_ARGS+=	--enable-df
PLIST.df=	yes
.else
CONFIGURE_ARGS+=	--disable-df
.endif

.if !empty(PKG_OPTIONS:Mdisk)
CONFIGURE_ARGS+=	--enable-disk
PLIST.disk=	yes
.else
CONFIGURE_ARGS+=	--disable-disk
.endif

.if !empty(PKG_OPTIONS:Mdns)
CONFIGURE_ARGS+=	--enable-dns
PLIST.dns=	yes
.else
CONFIGURE_ARGS+=	--disable-dns
.endif

.if !empty(PKG_OPTIONS:Memail)
CONFIGURE_ARGS+=	--enable-email
PLIST.email=	yes
.else
CONFIGURE_ARGS+=	--disable-email
.endif

.if !empty(PKG_OPTIONS:Mexec)
CONFIGURE_ARGS+=	--enable-exec
PLIST.exec=	yes
.else
CONFIGURE_ARGS+=	--disable-exec
.endif

.if !empty(PKG_OPTIONS:Mfilecount)
CONFIGURE_ARGS+=	--enable-filecount
PLIST.filecount=	yes
.else
CONFIGURE_ARGS+=	--disable-filecount
.endif

.if !empty(PKG_OPTIONS:Minterface)
.include "../../devel/libstatgrab/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libstatgrab=${BUILDLINK_PREFIX.libstatgraph}
CONFIGURE_ARGS+=	--enable-interface
PLIST.interface=	yes
.else
CONFIGURE_ARGS+=	--disable-interface
.endif

.if !empty(PKG_OPTIONS:Mload)
CONFIGURE_ARGS+=	--enable-load
PLIST.load=	yes
.else
CONFIGURE_ARGS+=	--disable-load
.endif

.if !empty(PKG_OPTIONS:Mlogfile)
CONFIGURE_ARGS+=	--enable-logfile
PLIST.logfile=	yes
.else
CONFIGURE_ARGS+=	--disable-logfile
.endif

.if !empty(PKG_OPTIONS:Mmatch_empty_counter)
CONFIGURE_ARGS+=	--enable-match_empty_counter
PLIST.match-empty-counter=	yes
.else
CONFIGURE_ARGS+=	--disable-match_empty_counter
.endif

.if !empty(PKG_OPTIONS:Mmatch_hashed)
CONFIGURE_ARGS+=	--enable-match_hashed
PLIST.match-hashed=	yes
.else
CONFIGURE_ARGS+=	--disable-match_hashed
.endif

.if !empty(PKG_OPTIONS:Mmatch_regex)
CONFIGURE_ARGS+=	--enable-match_regex
PLIST.match-regex=	yes
.else
CONFIGURE_ARGS+=	--disable-match_regex
.endif

.if !empty(PKG_OPTIONS:Mmatch_timediff)
CONFIGURE_ARGS+=	--enable-match_timediff
PLIST.match-timediff=	yes
.else
CONFIGURE_ARGS+=	--disable-match_timediff
.endif

.if !empty(PKG_OPTIONS:Mmatch_value)
CONFIGURE_ARGS+=	--enable-match_value
PLIST.match-value=	yes
.else
CONFIGURE_ARGS+=	--disable-match_value
.endif

.if !empty(PKG_OPTIONS:Mmbmon)
CONFIGURE_ARGS+=	--enable-mbmon
PLIST.mbmon=	yes
.else
CONFIGURE_ARGS+=	--disable-mbmon
.endif

.if !empty(PKG_OPTIONS:Mmemcachec)
.include "../../devel/libmemcache/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-memcachec
PLIST.memcachec=	yes
.else
CONFIGURE_ARGS+=	--disable-memcachec
.endif

.if !empty(PKG_OPTIONS:Mmemcached)
CONFIGURE_ARGS+=	--enable-memcached
PLIST.memcached=	yes
.else
CONFIGURE_ARGS+=	--disable-memcached
.endif

.if !empty(PKG_OPTIONS:Mmemory)
CONFIGURE_ARGS+=	--enable-memory
PLIST.memory=	yes
.else
CONFIGURE_ARGS+=	--disable-memory
.endif

.if !empty(PKG_OPTIONS:Mmultimeter)
CONFIGURE_ARGS+=	--enable-multimeter
PLIST.multimeter=	yes
.else
CONFIGURE_ARGS+=	--disable-multimeter
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql5-client/buildlink3.mk"
#CONFIGURE_ARGS+=       --with-libmysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--enable-mysql
PLIST.mysql=	yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mnetwork)
CONFIGURE_ARGS+=	--enable-network
PLIST.network=	yes
.else
CONFIGURE_ARGS+=	--disable-network
.endif

.if !empty(PKG_OPTIONS:Mnginx)
.include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nginx
PLIST.nginx=	yes
.else
CONFIGURE_ARGS+=	--disable-nginx
.endif

.if !empty(PKG_OPTIONS:Mnotify_desktop)
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-notify_desktop
PLIST.notify-desktop=	yes
.else
CONFIGURE_ARGS+=	--disable-notify_desktop
.endif

.if !empty(PKG_OPTIONS:Mnotify_email)
.include "../../mail/libesmtp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-notify_email
PLIST.notify-email=	yes
.else
CONFIGURE_ARGS+=	--disable-notify_email
.endif

.if !empty(PKG_OPTIONS:Mntpd)
CONFIGURE_ARGS+=	--enable-ntpd
PLIST.ntpd=	yes
.else
CONFIGURE_ARGS+=	--disable-ntpd
.endif

.if !empty(PKG_OPTIONS:Molsrd)
CONFIGURE_ARGS+=	--enable-olsrd
PLIST.olsrd=	yes
.else
CONFIGURE_ARGS+=	--disable-olsrd
.endif

.if !empty(PKG_OPTIONS:Mopenvpn)
CONFIGURE_ARGS+=	--enable-openvpn
PLIST.openvpn=	yes
.else
CONFIGURE_ARGS+=	--disable-openvpn
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
PLIST.perl=	yes
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(PKG_OPTIONS:Mpostgresql)
.include "../../databases/postgresql84-client/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-postgresql
PLIST.postgresql=	yes
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif

.if !empty(PKG_OPTIONS:Mpowerdns)
CONFIGURE_ARGS+=	--enable-powerdns
PLIST.powerdns=	yes
.else
CONFIGURE_ARGS+=	--disable-powerdns
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
CONFIGURE_ARGS+=	--enable-python
PLIST.python=	yes
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if !empty(PKG_OPTIONS:Mswap)
CONFIGURE_ARGS+=	--enable-swap
PLIST.swap=	yes
.else
CONFIGURE_ARGS+=	--disable-swap
.endif

.if !empty(PKG_OPTIONS:Msyslog)
CONFIGURE_ARGS+=	--enable-syslog
PLIST.syslog=	yes
.else
CONFIGURE_ARGS+=	--disable-syslog
.endif

.if !empty(PKG_OPTIONS:Mtable)
CONFIGURE_ARGS+=	--enable-table
PLIST.table=	yes
.else
CONFIGURE_ARGS+=	--disable-table
.endif

.if !empty(PKG_OPTIONS:Mtail)
CONFIGURE_ARGS+=	--enable-tail
PLIST.tail=	yes
.else
CONFIGURE_ARGS+=	--disable-tail
.endif

.if !empty(PKG_OPTIONS:Mtarget_notification)
CONFIGURE_ARGS+=	--enable-target_notification
PLIST.target-notification=	yes
.else
CONFIGURE_ARGS+=	--disable-target_notification
.endif

.if !empty(PKG_OPTIONS:Mtarget_replace)
CONFIGURE_ARGS+=	--enable-target_replace
PLIST.target-replace=	yes
.else
CONFIGURE_ARGS+=	--disable-target_replace
.endif

.if !empty(PKG_OPTIONS:Mtarget_scale)
CONFIGURE_ARGS+=	--enable-target_scale
PLIST.target-scale=	yes
.else
CONFIGURE_ARGS+=	--disable-target_scale
.endif

.if !empty(PKG_OPTIONS:Mtarget_set)
CONFIGURE_ARGS+=	--enable-target_set
PLIST.target-set=	yes
.else
CONFIGURE_ARGS+=	--disable-target_set
.endif

.if !empty(PKG_OPTIONS:Mtcpconns)
CONFIGURE_ARGS+=	--enable-tcpconns
PLIST.tcpconns=	yes
.else
CONFIGURE_ARGS+=	--disable-tcpconns
.endif

.if !empty(PKG_OPTIONS:Mteamspeak2)
CONFIGURE_ARGS+=	--enable-teamspeak2
PLIST.teamspeak2=	yes
.else
CONFIGURE_ARGS+=	--disable-teamspeak2
.endif

.if !empty(PKG_OPTIONS:Mted)
CONFIGURE_ARGS+=	--enable-ted
PLIST.ted=	yes
.else
CONFIGURE_ARGS+=	--disable-ted
.endif

.if !empty(PKG_OPTIONS:Munixsock)
CONFIGURE_ARGS+=	--enable-unixsock
PLIST.unixsock=	yes
.else
CONFIGURE_ARGS+=	--disable-unixsock
.endif

.if !empty(PKG_OPTIONS:Muptime)
CONFIGURE_ARGS+=	--enable-uptime
PLIST.uptime=	yes
.else
CONFIGURE_ARGS+=	--disable-uptime
.endif

.if !empty(PKG_OPTIONS:Musers)
CONFIGURE_ARGS+=	--enable-users
PLIST.users=	yes
.else
CONFIGURE_ARGS+=	--disable-users
.endif

.if !empty(PKG_OPTIONS:Muuid)
CONFIGURE_ARGS+=	--enable-uuid
PLIST.uuid=	yes
.else
CONFIGURE_ARGS+=	--disable-uuid
.endif

.if !empty(PKG_OPTIONS:Mwrite_http)
.include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-write_http
PLIST.write-http=	yes
.else
CONFIGURE_ARGS+=	--disable-write_http
.endif
