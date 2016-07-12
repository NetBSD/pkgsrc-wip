# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	3.0.2
PKGNAME=	cinnamon-menus-3.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=/linuxmint/cinnamon-menus/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-menus
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

PKGCONFIG_OVERRIDE+=	libmenu/libcinnamon-menu-3.0.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
