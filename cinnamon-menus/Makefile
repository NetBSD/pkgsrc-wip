# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cinnamon-menus_2.2.0.orig
PKGNAME=	cinnamon-menus-2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/c/cinnamon-menus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/linuxmint/cinnamon-menus
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=		${WRKDIR}/cinnamon-menus-2.2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmenu/libcinnamon-menu-3.0.pc.in

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
