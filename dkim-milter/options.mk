# $NetBSD: options.mk,v 1.8 2007/10/09 18:18:58 jukka Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dkim-milter
PKG_SUPPORTED_OPTIONS=	inet6 dkim-stats arlib

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
### Install dkim-stats(8).
###
.if !empty(PKG_OPTIONS:Mdkim-stats)
PLIST_SUBST+=		WITH_STATS=''
SUBST_SED.libs+=	-e 's|@STATS@||g'
SUBST_SED.libs+=	-e 's|@DBLIB@|db|g'
stats-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dkim-filter/dkim-stats ${PREFIX}/sbin;
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-stats.8 ${PREFIX}/${PKGMANDIR}/man8
.else
PLIST_SUBST+=		WITH_STATS='@comment '
SUBST_SED.libs+=	-e 's|@STATS@|dnl|g'
SUBST_SED.libs+=	-e 's|@DBLIB@||g'
stats-install:
.endif

###
### Use asynchronous DNS resolver library shipping with dkim-milter.
###
.if !empty(PKG_OPTIONS:Marlib)
PLIST_SUBST+=		WITH_ARLIB=''
SUBST_SED.libs+=	-e 's|@RESOLVLIB@||g'
SUBST_SED.libs+=	-e 's|@ARLIB@||g'
arlib-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_LIB} libar/libar.a ${PREFIX}/lib;
	${INSTALL_MAN} ${WRKSRC}/libar/ar.3 ${PREFIX}/${PKGMANDIR}/man3
INSTALLATION_DIRS+=	${PKGMANDIR}/man3
.else
PLIST_SUBST+=		WITH_ARLIB='@comment '
SUBST_SED.libs+=	-e 's|@RESOLVLIB@|resolv bind|g'
SUBST_SED.libs+=	-e 's|@ARLIB@|dnl|g'
arlib-install:
.endif
