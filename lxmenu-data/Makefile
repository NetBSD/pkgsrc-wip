# $NetBSD: $

DISTNAME=	lxmenu-data-0.1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	LXDE menu data
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool

LXDE_CONF=		share/examples/lxde
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${LXDE_CONF}
PKG_SYSCONFSUBDIR=	xdg

CONF_FILES=	${LXDE_CONF}/xdg/menus/lxde-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxde-applications.menu
.include "../../mk/bsd.pkg.mk"
