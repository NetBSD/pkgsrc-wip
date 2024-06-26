# $NetBSD: Makefile,v 1.29 2024/04/06 08:04:46 wiz Exp $

DISTNAME=	lxqt-archiver-1.0.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-archiver/
COMMENT=	Simple and lightweight Qt file archiver
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl bsdtar:run gzip:run 7za:run gtar:run bzip2:run unzip:run zip:run xz:run

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../wip/lxqt2-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wip/libfm-qt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
