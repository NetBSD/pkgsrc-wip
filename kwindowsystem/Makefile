# $NetBSD: Makefile,v 1.1 2015/04/11 13:00:41 krytarowski Exp $

DISTNAME=	kwindowsystem-5.9.0
CATEGORIES=	x11
MASTER_SITES=	http://download.kde.org/stable/frameworks/5.9/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.kde.org/projects/frameworks/kwindowsystem
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../wip/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
