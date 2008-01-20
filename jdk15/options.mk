# $NetBSD: options.mk,v 1.9 2008/01/20 15:23:09 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk15
PKG_SUPPORTED_OPTIONS=		jdk15-jce jdk15-plugin inet6
PKG_SUGGESTED_OPTIONS=		jdk15-plugin
PKG_OPTIONS_LEGACY_VARS+=	JDK15_USE_JCE:jdk15-jce

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		DONT_ENABLE_IPV6=YES
.endif

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjdk15-jce)
DISTFILES+=	jce_policy-1_5_0.zip
PLIST_SRC+=	PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; ${PAX} -rw -pp . ${JDKIMAGEDIR}/jre/lib/security
.endif


###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk15-plugin)

MOZILLA=	${PKG_OPTIONS:@opt@${PKG_OPTIONS_GROUP.gecko:M${opt}}@}
MAKE_ENV+=	BROWSER=${MOZILLA:Q}
MAKE_ENV+=	ALT_MOZILLA_HEADERS_PATH=${LOCALBASE:Q}/include/${MOZILLA}

.include "../../www/seamonkey/gecko-depends.mk"
# Check: is nspr necessary?
#.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_DEPMETHOD.nspr=	build
PLIST_SRC+=			PLIST.plugin
MESSAGE_SRC+=			MESSAGE.plugin

.else
MAKE_ENV+=			BUILD_PLUGIN=false
.endif
