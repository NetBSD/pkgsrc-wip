# $NetBSD: options.mk,v 1.2 2008/01/20 14:04:55 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk16
PKG_SUPPORTED_OPTIONS=		jdk16-jce inet6 debug fastdebug # jdk16-plugin
PKG_SUGGESTED_OPTIONS=		# jdk16-plugin 
PKG_OPTIONS_LEGACY_VARS+=	JDK16_USE_JCE:jdk16-jce

# fixme
#.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjdk16-jce)
DISTFILES+=	jce_policy-6.zip
PLIST_SRC+=	PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; ${PAX} -rw -pp . ${JDKIMAGEDIR}/jre/lib/security
.endif


###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk16-plugin)
PKG_FAIL_REASON+=	Sorry, the plugin option is broken. Please fix it!
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
