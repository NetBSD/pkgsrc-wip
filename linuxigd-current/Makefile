# $NetBSD: Makefile,v 1.4 2006/02/06 11:39:19 obache Exp $
#

DISTNAME=	linuxigd-0.99
CATEGORIES=	net
MASTER_SITES=	#

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake

CVS_REPOSITORIES=	linux-igd
CVS_ROOT.linux-igd=	${CVS_ROOT_SOURCEFORGE}/linux-igd
CVS_MODULE.linux-igd=	linux-igd

.include "options.mk"

INSTALLATION_DIRS=	${PKG_SYSCONFDIR:S|^${PREFIX}/||}/linuxigd

EGDIR=		${PREFIX}/share/examples/linuxigd
CONF_FILES=	${EGDIR:Q}/upnpd.conf ${PKG_SYSCONFDIR:Q}/upnpd.conf
CONF_FILES+=	${EGDIR:Q}/dummy.xml ${PKG_SYSCONFDIR:Q}/linuxigd/dummy.xml
CONF_FILES+=	${EGDIR:Q}/gateconnSCPD.xml ${PKG_SYSCONFDIR:Q}/linuxigd/gateconnSCPD.xml
CONF_FILES+=	${EGDIR:Q}/gatedesc.xml ${PKG_SYSCONFDIR:Q}/linuxigd/gatedesc.xml
CONF_FILES+=	${EGDIR:Q}/gateicfgSCPD.xml ${PKG_SYSCONFDIR:Q}/linuxigd/gateicfgSCPD.xml
CONF_FILES+=	${EGDIR:Q}/ligd.gif ${PKG_SYSCONFDIR:Q}/linuxigd/ligd.gif
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	config.c etc/upnpd.conf
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp12/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
