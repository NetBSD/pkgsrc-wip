# $NetBSD$

DISTNAME=	python-metar-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-metar/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/python-metar/python-metar/
COMMENT=	TODO: Short description of the package
# sort of 1-clause BSD
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/${DISTNAME}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
