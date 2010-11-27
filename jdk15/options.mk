# $NetBSD: options.mk,v 1.16 2010/11/27 14:04:52 ftigeot Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk15
PKG_SUPPORTED_OPTIONS=		sun-jre-jce jdk15-plugin inet6
#PKG_SUGGESTED_OPTIONS=		jdk15-plugin

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


###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk15-plugin)

MOZILLA=	${PKG_OPTIONS:@opt@${PKG_OPTIONS_GROUP.gecko:M${opt}}@}
MAKE_ENV+=	BROWSER=${MOZILLA:Q}
MAKE_ENV+=	ALT_MOZILLA_HEADERS_PATH=${PREFIX:Q}/include/${MOZILLA}

#.include "../../www/seamonkey/gecko-depends.mk"
# Check: is nspr necessary?
#.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_DEPMETHOD.nspr=	build
PLIST.plugin=		yes
MESSAGE_SRC+=		MESSAGE.plugin

.else
MAKE_ENV+=		BUILD_PLUGIN=false
.endif
