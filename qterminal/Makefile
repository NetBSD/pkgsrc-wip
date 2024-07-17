# $NetBSD: Makefile,v 1.31 2024/04/06 08:07:13 wiz Exp $

DISTNAME=	qterminal-2.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qterminal/
COMMENT=	Terminal emulator for Qt5
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${PREFIX}/qt6

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../wip/lxqt2-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wip/qtermwidget/buildlink3.mk"
.include "../../wip/layer-shell-qt6/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
