# $NetBSD: Makefile,v 1.10 2007/04/01 02:19:12 obache Exp $
#

DISTNAME=	linuxigd-0.99
CATEGORIES=	net
MASTER_SITES=	#

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux-igd.sourceforge.net/
COMMENT=	Linux UPnP Internet Gateway Device

USE_TOOLS+=	gmake pkg-config

CVS_REPOSITORIES=	linux-igd
CVS_ROOT.linux-igd=	${CVS_ROOT_SOURCEFORGE:S/%PROJECT%/linux-igd/g}
CVS_MODULE.linux-igd=	linux-igd

WRKSRC=		${WRKDIR}/linux-igd

.include "options.mk"

INSTALLATION_DIRS=	${PKG_SYSCONFDIR:S|^${PREFIX}/||}/linuxigd

MAKE_ENV+=	LIBS=${LIBS:M*:Q}

CONF_FILES=	${PREFIX}/share/examples/upnpd.conf ${PKG_SYSCONFDIR:Q}/upnpd.conf
RCD_SCRIPTS=	linuxigd

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	pre-configure
SUBST_FILES.cfgdir=	globals.h etc/upnpd.conf
SUBST_SED.cfgdir=	-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|'

.include "../../wip/libupnp/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
