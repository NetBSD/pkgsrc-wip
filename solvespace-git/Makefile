# $NetBSD$

PKGNAME=	solvespace-2.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=solvespace/}

GIT_REPOSITORIES=	solvespace
GIT_REPO.solvespace=	https://github.com/solvespace/solvespace.git
WRKSRC=			${WRKDIR}/solvespace

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://solvespace.com/
COMMENT=	Parametric 2D/3D CAD program
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Build out-of-tree
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${MKDIR} ${WRKSRC}/_build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
