# $NetBSD: options.mk,v 1.1 2013/03/29 21:17:02 florian-geiges Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.znc
PKG_SUPPORTED_OPTIONS=	debug poll optimization ipv6 openssl perl python tcl tdns cyrus
PKG_SUGGESTED_OPTIONS=	poll optimization ipv6 openssl tdns

.include		"../../mk/bsd.prefs.mk"
.include 		"../../mk/bsd.options.mk"

#
# Debug build
#
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

#
# Use select() instead of poll()
#
.if empty(PKG_OPTIONS:Mpoll)
CONFIGURE_ARGS+=	--disable-poll
.endif

#
# Non-optimized build
#
.if empty(PKG_OPTIONS:Moptimization)
CONFIGURE_ARGS+=	--disable-optimization
.endif

#
# IPv6 support
#
.if empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

#
# OpenSSL support
#
.if empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--disable-openssl
.else
PLIST_SRC+=		PLIST.openssl
.endif

#
# Threaded DNS
#
.if empty(PKG_OPTIONS:Mtdns)
CONFIGURE_ARGS+=	--disable-tdns
.endif

#
# Perl support
#
.if !empty(PKG_OPTIONS:Mperl)
.include		"../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-perl
USE_TOOLS+=		perl
PLIST_SRC+=		PLIST.perl
.endif

#
# TCL option
#
.if !empty(PKG_OPTIONS:Mtcl)
.include		"../../lang/tcl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib
PLIST_SRC+=		PLIST.tcl
.endif

#
# Python support
#
.if !empty(PKG_OPTIONS:Mpython)
.include		"../../lang/python31/buildlink3.mk"
BUILD_DEPENDS+=		python31>=3.1:../../lang/python31
DEPENDS+=		python31>=3.1:../../lang/python31
CONFIGURE_ARGS+=	--enable-python=python-3.1
USE_LANGUAGES+=		python
.endif

#
# Cyrus SASL support
#
.if !empty(PKG_OPTIONS:Mcyrus)
.include		"../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cyrus
PLIST_SRC+=		PLIST.cyrus
.endif
