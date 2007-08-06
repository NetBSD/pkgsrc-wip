# $NetBSD: options.mk,v 1.2 2007/08/06 19:47:29 jukka Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dk-milter
PKG_SUPPORTED_OPTIONS=	inet6 arlib
PKG_SUGGESTED_OPTIONS=	arlib

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
SUBST_SED.libs+=	-e 's|@INET6@||g'
.else
SUBST_SED.libs+=	-e 's|@INET6@|dnl|g'
.endif

###
### Use asynchronous DNS resolver library shipping with dk-milter.
###
.if !empty(PKG_OPTIONS:Marlib)
SUBST_SED.libs+=	-e 's|@RESOLVLIB@||g'
SUBST_SED.libs+=	-e 's|@ARLIB@||g'
.else
SUBST_SED.libs+=	-e 's|@RESOLVLIB@|resolv bind|g'
SUBST_SED.libs+=	-e 's|@ARLIB@|dnl|g'
.endif
