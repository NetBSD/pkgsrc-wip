# $NetBSD: Makefile,v 1.1 2015/04/11 11:07:19 krytarowski Exp $

GITHUB_PROJECT=	libqtxdg
DISTNAME=	1.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=lxde/libqtxdg/}
COMMENT=	Qt implementation of freedesktop.org xdg specs
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/libqtxdg-1.2.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
