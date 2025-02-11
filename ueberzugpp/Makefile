# $NetBSD$

DISTNAME=	ueberzugpp-2.9.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jstkdng/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jstkdng/ueberzugpp/
COMMENT=	Command line utility allowing to draw images on terminals
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/CLI11/buildlink3.mk"
.include "../../devel/range-v3/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../graphics/chafa/buildlink3.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../wip/libvips/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
