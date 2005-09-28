# $NetBSD: options.mk,v 1.1.1.1 2005/09/28 13:56:35 ghen Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk15
PKG_SUPPORTED_OPTIONS=		jdk15-jce jdk15-plugin
PKG_SUGGESTED_OPTIONS=		jdk15-plugin
PKG_OPTIONS_LEGACY_VARS+=	JDK15_USE_JCE:jdk15-jce
PKG_OPTIONS_REQUIRED_GROUPS+=	mozilla
PKG_OPTIONS_GROUP.mozilla=	firefox mozilla mozilla-gtk2 firefox-gtk1
PKG_SUGGESTED_OPTIONS=		mozilla-gtk2

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
### Mozilla headers
###
MOZILLA=	${PKG_OPTIONS:@opt@${PKG_OPTIONS_GROUP.mozilla:M${opt}}@}
.include "../../www/${MOZILLA}/buildlink3.mk"
MAKE_ENV+=	BROWSER=${MOZILLA}

###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk15-plugin)
.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_DEPMETHOD.nspr=	build
PLIST_SRC+=			PLIST.plugin
.else
MAKE_ENV+=			NO_PLUGIN=YES
.endif
