# $NetBSD: Makefile,v 1.1 2015/04/11 14:44:40 krytarowski Exp $

DISTNAME=	kguiaddons-5.9.0
CATEGORIES=	devel
MASTER_SITES=	http://download.kde.org/stable/frameworks/5.9/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.kde.org/projects/frameworks/kguiaddons
COMMENT=	Addons to QtGui
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
