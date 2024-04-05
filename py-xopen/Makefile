# $NetBSD: Makefile,v 1.14 2019/09/06 06:04:17 adam Exp $

DISTNAME=	xopen-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xopen/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/xopen
COMMENT=	Open compressed files transparently
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	pbzip2-[0-9]*:../../archivers/pbzip2
DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	${PYPKGPREFIX}-zstandard-[0-9]*:../../archivers/py-zstandard
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
