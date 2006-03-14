# $NetBSD: Makefile,v 1.6 2006/03/14 01:28:01 jlamwww Exp $
#

DISTNAME=	linuxigd-0.92
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-igd/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "options.mk"

WRKSRC=		${WRKDIR}/linux-igd

PKG_SYSCONFSUBDIR=	linuxigd

EGDIR=		${PREFIX}/share/examples/linuxigd
CONF_FILES=	${EGDIR:Q}/gateconnSCPD.xml ${PKG_SYSCONFDIR:Q}/gateconnSCPD.xml
CONF_FILES+=	${EGDIR:Q}/gatedesc.skl ${PKG_SYSCONFDIR:Q}/gatedesc.skl
CONF_FILES+=	${EGDIR:Q}/gatedesc.xml ${PKG_SYSCONFDIR:Q}/gatedesc.xml
CONF_FILES+=	${EGDIR:Q}/gateicfgSCPD.xml ${PKG_SYSCONFDIR:Q}/gateicfgSCPD.xml
CONF_FILES+=	${EGDIR:Q}/gateinfoSCPD.xml ${PKG_SYSCONFDIR:Q}/gateinfoSCPD.xml
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	gateway.h
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
