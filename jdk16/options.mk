# $NetBSD: options.mk,v 1.6 2012/06/12 15:46:34 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk16
PKG_SUPPORTED_OPTIONS=		sun-jre-jce inet6 debug fastdebug # jdk16-plugin
PKG_SUGGESTED_OPTIONS=		inet6 # jdk16-plugin

# fixme
#.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		DONT_ENABLE_IPV6=YES
.endif

.if empty(PKG_OPTIONS:Mdebug)
MAKE_ENV+=		SKIP_DEBUG_BUILD=true
.else
MAKE_ENV+=		SKIP_DEBUG_BUILD=false
.endif

.if empty(PKG_OPTIONS:Mfastdebug)
MAKE_ENV+=		SKIP_FASTDEBUG_BUILD=true
.else
MAKE_ENV+=		SKIP_FASTDEBUG_BUILD=false
.endif

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Msun-jre-jce)
DISTFILES+=	jce_policy-6.zip
PLIST_SRC+=	PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; pax -rw -pp . ${JDKIMAGEDIR}/jre/lib/security
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
