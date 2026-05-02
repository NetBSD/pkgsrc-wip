# $NetBSD$

DISTNAME=	pybind11_json-0.2.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
GITHUB_PROJECT=	pybind11_json
MASTER_SITES=	${MASTER_SITE_GITHUB:=pybind/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/pybind/pybind11_json/
COMMENT=	Bridge from nlohmann::json to pybind11
LICENSE=	modified-bsd

#DISTDIR=	${DISTNAME}
USE_LANGUAGES=	c c++

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../lang/python/pyversion.mk"
CMAKE_CONFIGURE_ARGS+=-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

.include "../../devel/cmake/build.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
