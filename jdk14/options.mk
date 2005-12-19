# $NetBSD: options.mk,v 1.4 2005/12/19 13:32:01 ghen Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk14
PKG_SUPPORTED_OPTIONS=		jdk14-jce jdk14-plugin inet6
PKG_SUGGESTED_OPTIONS=		jdk14-plugin
PKG_OPTIONS_LEGACY_VARS+=	JDK14_USE_JCE:jdk14-jce

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjdk14-jce)
DISTFILES+=			jce_policy-1_4_2.zip
PLIST_SRC+=			PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; ${PAX} -rw -pe . ${JDKIMAGEDIR}/jre/lib/security
.endif

###
### Mozilla plugin
###
.if !empty(PKG_OPTIONS:Mjdk14-plugin)
.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_DEPMETHOD.nspr=	build
PLIST_SRC+=			PLIST.plugin
.else
MAKE_ENV+=			NO_PLUGIN=YES
.endif

###
### Disable IPv6 support such that users don't have
### to disable the net.inet6.ip6.v6only sysctl
###
.if empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=			DONT_ENABLE_IPV6=YES
.endif
