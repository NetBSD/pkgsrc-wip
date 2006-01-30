# $NetBSD: Makefile,v 1.2 2006/01/30 01:19:42 lsed Exp $
#

DISTNAME=	linuxigd-0.99
CATEGORIES=	net
MASTER_SITES=   #

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_PKGINSTALL=	yes
USE_TOOLS+= gmake

CVS_REPOSITORIES=	linux-igd
CVS_ROOT.linux-igd=	${CVS_REPOSITORY_SOURCEFORGE}/linux-igd
CVS_MODULE.linux-igd=	linux-igd

.include "options.mk"

INSTALLATION_DIRS=	${PKG_SYSCONFDIR:S|^${PREFIX}/||}/linuxigd

EGDIR=		${PREFIX}/share/examples/linuxigd
CONF_FILES=	${EGDIR}/upnpd.conf ${PKG_SYSCONFDIR}/upnpd.conf
CONF_FILES+=	${EGDIR}/dummy.xml ${PKG_SYSCONFDIR}/linuxigd/dummy.xml
CONF_FILES+=	${EGDIR}/gateconnSCPD.xml ${PKG_SYSCONFDIR}/linuxigd/gateconnSCPD.xml
CONF_FILES+=	${EGDIR}/gatedesc.xml ${PKG_SYSCONFDIR}/linuxigd/gatedesc.xml
CONF_FILES+=	${EGDIR}/gateicfgSCPD.xml ${PKG_SYSCONFDIR}/linuxigd/gateicfgSCPD.xml
CONF_FILES+=	${EGDIR}/ligd.gif ${PKG_SYSCONFDIR}/linuxigd/ligd.gif
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=         cfgdir
SUBST_STAGE.cfgdir=     pre-configure
SUBST_FILES.cfgdir=     config.c etc/upnpd.conf
SUBST_SED.cfgdir=       -e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp12/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
