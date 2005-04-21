# $NetBSD: Makefile,v 1.3 2005/04/21 13:04:57 obache Exp $
#

DISTNAME=	linuxigd-0.92
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=linux-igd/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_LANGUAGES=	c c++
USE_PKGINSTALL=	yes
USE_GNU_TOOLS+= make

.include "options.mk"

WRKSRC=		${WRKDIR}/linux-igd

PKG_SYSCONFSUBDIR?=	linuxigd

EGDIR=		${PREFIX}/share/examples/linuxigd
CONF_FILES=	${EGDIR}/gateconnSCPD.xml ${PKG_SYSCONFDIR}/gateconnSCPD.xml
CONF_FILES+=	${EGDIR}/gatedesc.skl ${PKG_SYSCONFDIR}/gatedesc.skl
CONF_FILES+=	${EGDIR}/gatedesc.xml ${PKG_SYSCONFDIR}/gatedesc.xml
CONF_FILES+=	${EGDIR}/gateicfgSCPD.xml ${PKG_SYSCONFDIR}/gateicfgSCPD.xml
CONF_FILES+=	${EGDIR}/gateinfoSCPD.xml ${PKG_SYSCONFDIR}/gateinfoSCPD.xml
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	gateway.h
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
