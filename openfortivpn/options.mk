# $NetBSD: options.mk$

PKG_OPTIONS_VAR=	PKG_OPTIONS.openfortivpn
PKG_SUPPORTED_OPTIONS=	openfortivpn-proc
PKG_SUPPORTED_OPTIONS+=	openfortivpn-enable-resolvconf
PKG_SUPPORTED_OPTIONS+=	openfortivpn-obsolete
PKG_SUPPORTED_OPTIONS+=	openfortivpn-rt-dst
PKG_SUPPORTED_OPTIONS+=	openfortivpn-netstat
PKG_SUPPORTED_OPTIONS+=	openfortivpn-pppd
PKG_SUPPORTED_OPTIONS+=	openfortivpn-ppp
PKG_SUPPORTED_OPTIONS+=	openfortivpn-with-resolvconf
PKG_SUPPORTED_OPTIONS+=	openfortivpn-systemdsystemunitdir

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

.if !empty(PKG_OPTIONS:Mopenfortivpn-proc)
CONFIGURE_ARGS+=	--enable-proc
.else
CONFIGURE_ARGS+=	--disable-proc
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-enable-resolvconf)
CONFIGURE_ARGS+=	--enable-resolvconf
.else
CONFIGURE_ARGS+=	--disable-resolvconf
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-obsolete)
CONFIGURE_ARGS+=	--enable-obsolete
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-rt-dst)
CONFIGURE_ARGS+=	--with-rt_dst
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-netstat)
CONFIGURE_ARGS+=	--with-netstat=${NETSTAT_PATH:Q}
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-pppd)
CONFIGURE_ARGS+=	--with-pppd=${PPPD_PATH:Q}
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-ppp)
CONFIGURE_ARGS+=	--with-ppp=${PPP_PATH:Q}
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-with-resolvconf)
CONFIGURE_ARGS+=	--with-resolvconf=${RESOLVCONF_PATH:Q}
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-systemdsystemunitdir)
CONFIGURE_ARGS+=	--with-systemdsystemunitdir=${SYSTEMDSYSTEMUNITDIR:Q}
.endif
