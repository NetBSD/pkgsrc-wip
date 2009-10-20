# $NetBSD: options.mk,v 1.6 2009/10/20 10:24:22 absd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdk14
PKG_SUPPORTED_OPTIONS=		sun-jre-jce jdk14-plugin inet6
PKG_SUGGESTED_OPTIONS=		jdk14-plugin

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Msun-jre-jce)
DISTFILES+=			jce_policy-1_4_2.zip
PLIST_SRC+=			PLIST.jce
post-build:
	cd ${WRKDIR}/jce ; pax -rw -pe . ${JDKIMAGEDIR}/jre/lib/security
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
