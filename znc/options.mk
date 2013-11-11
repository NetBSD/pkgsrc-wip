# $NetBSD: options.mk,v 1.4 2013/11/11 10:56:53 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.znc
PKG_SUPPORTED_OPTIONS=	debug poll optimization inet6 openssl perl python tcl tdns sasl
PKG_SUGGESTED_OPTIONS=	poll optimization inet6 openssl tdns

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
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

#
# OpenSSL support
#
.if empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--disable-openssl
.else
.include "../../security/openssl/buildlink3.mk"
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
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
PLIST_SRC+=		PLIST.tcl
.endif

#
# Python support
#
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PY_PEP3147=	no
.include		"../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python=python-${PYVERSSUFFIX}
PLIST_SRC+=		PLIST.python
.endif

#
# Cyrus SASL support
#
.if !empty(PKG_OPTIONS:Msasl)
.include		"../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cyrus
PLIST_SRC+=		PLIST.cyrus
.endif
