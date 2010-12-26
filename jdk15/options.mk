# $NetBSD: options.mk,v 1.17 2010/12/26 12:27:10 ftigeot Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk15
PKG_SUPPORTED_OPTIONS=		sun-jre-jce inet6

#.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		DONT_ENABLE_IPV6=YES
.endif

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Msun-jre-jce)
DISTFILES+=	jce_policy-1_5_0.zip
PLIST.jce=	yes
post-build:
	cd ${WRKDIR}/jce ; pax -rw -pp . ${JDKIMAGEDIR}/jre/lib/security
.endif
