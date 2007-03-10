# $NetBSD: options.mk,v 1.5 2007/03/10 17:11:05 briandealwis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk15
PKG_SUPPORTED_OPTIONS=		jdk15-jce jdk15-plugin
PKG_SUGGESTED_OPTIONS=		jdk15-plugin
PKG_OPTIONS_LEGACY_VARS+=	JDK15_USE_JCE:jdk15-jce

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjdk15-jce)
DISTFILES+=	jce_policy-1_5_0.zip
PLIST_SRC+=	PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; ${PAX} -rw -pe . ${JDKIMAGEDIR}/jre/lib/security
.endif


###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk15-plugin)

MOZILLA=	${PKG_OPTIONS:@opt@${PKG_OPTIONS_GROUP.gecko:M${opt}}@}
#.include "../../www/${MOZILLA}/buildlink3.mk"
MAKE_ENV+=	BROWSER=${MOZILLA:Q}
MAKE_ENV+=	ALT_MOZILLA_HEADERS_PATH=${LOCALBASE:Q}/include/${MOZILLA}

.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_DEPMETHOD.nspr=	build
PLIST_SRC+=			PLIST.plugin

.else
MAKE_ENV+=			NO_PLUGIN=YES
.endif
