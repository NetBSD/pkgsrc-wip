# $NetBSD$

GITHUB_PROJECT=	Uranium
GITHUB_TAG=	4.13.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/Uranium/
COMMENT=	Python framework for building 3D printing related applications
LICENSE=	gnu-lgpl-v3

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-shapely-[0-9]*:../../wip/py-shapely

pre-install:
	find ${WRKSRC} -type f -name "*.orig" | xargs ${RM}

PY_PATCHPLIST=YES

.include "../../devel/cmake/version.mk"

PLIST_SUBST+=	CMAKE_API=${CMAKE_API}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/libArcus/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
