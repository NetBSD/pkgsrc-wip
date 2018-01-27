# $NetBSD: options.mk,v 1.2 2013/03/30 08:17:43 florian-geiges Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libifstat
PKG_SUPPORTED_OPTIONS=	debug optimization proc kstat ifmib ifdata route kvm dlpi win32 snmp snmp-crypto
PKG_SUGGESTED_OPTIONS=

.include		"../../mk/bsd.prefs.mk"
.include		"../../mk/bsd.options.mk"

#
# Debug build
#
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

#
# Optimized build
#
.if !empty(PKG_OPTIONS:Moptimization)
CONFIGURE_ARGS+=	--enable-optim
.endif

#
# /proc/net/dev driver
#
.if !empty(PKG_OPTIONS:Mproc)
CONFIGURE_ARGS+=	--with-proc
.else
CONFIGURE_ARGS+=	--without-proc
.endif

#
# kstat(3K) driver
#
.if !empty(PKG_OPTIONS:Mkstat)
CONFIGURE_ARGS+=	--with-kstat
.else
CONFIGURE_ARGS+=	--without-kstat
.endif

#
# ifmib(4) driver
#
.if !empty(PKG_OPTIONS:Mifmib)
CONFIGURE_ARGS+=	--with-ifmib
.else
CONFIGURE_ARGS+=	--without-ifmib
.endif

#
# ifdata ioctl driver
#
.if !empty(PKG_OPTIONS:Mifdata)
CONFIGURE_ARGS+=	--with-ifdata
.else
CONFIGURE_ARGS+=	--without-ifdata
.endif

#
# route(4) sysctl driver
#
.if !empty(PKG_OPTIONS:Mroute)
CONFIGURE_ARGS+=	--with-route
.else
CONFIGURE_ARGS+=	--without-route
.endif

#
# kvm(3) driver
#
.if !empty(PKG_OPTIONS:Mkvm)
CONFIGURE_ARGS+=	--with-kvm
.else
CONFIGURE_ARGS+=	--without-kvm
.endif

#
# HP DLPI driver
#
.if !empty(PKG_OPTIONS:Mdlpi)
CONFIGURE_ARGS+=	--with-dlpi
.else
CONFIGURE_ARGS+=	--without-dlpi
.endif

#
# Win32 driver
#
.if !empty(PKG_OPTIONS:Mwin32)
CONFIGURE_ARGS+=	--with-win32
.else
CONFIGURE_ARGS+=	--without-win32
.endif

#
# UCD-SNMP driver
#
.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=        --with-snmp
.else
CONFIGURE_ARGS+=        --without-snmp
.endif

#
# force -lcrypto linking for UCD-SNMP
#
.if !empty(PKG_OPTIONS:Msnmp-crypto)
CONFIGURE_ARGS+=	--with-libcrypto
.else
CONFIGURE_ARGS+=	--without-libcrypto
.endif
