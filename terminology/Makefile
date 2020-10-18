# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=	terminology-1.8.1
CATEGORIES=	x11
PKGREVISION=    1
MASTER_SITES=	https://download.enlightenment.org/rel/apps/terminology/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.enlightenment.org/about-terminology
COMMENT=	Enlightenment terminal
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
