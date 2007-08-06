# $NetBSD: options.mk,v 1.5 2007/08/06 11:16:22 jukka Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dkim-milter
PKG_SUPPORTED_OPTIONS=	inet6 dkim-stats

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
SUBST_SED.libs+=	-e 's|@INET6@||'
.else
SUBST_SED.libs+=	-e 's|@INET6@|dnl|'
.endif

###
### Install dkim-stats(8).
###
.if !empty(PKG_OPTIONS:Mdkim-stats)
SUBST_SED.libs+=	-e 's|@STATS@||'
PLIST_SRC+=		PLIST.stats
stats-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dkim-filter/dkim-stats ${PREFIX}/sbin;
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-stats.8 ${PREFIX}/${PKGMANDIR}/man8
.else
SUBST_SED.libs+=	-e 's|@STATS@|dnl|'
stats-install:
.endif
