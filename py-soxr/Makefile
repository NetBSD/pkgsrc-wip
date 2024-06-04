# $NetBSD$

DISTNAME=	soxr-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/soxr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dofuuz/python-soxr
COMMENT=	Sample-rate conversion library for Python
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

PYTHON_PLATFORM=	${LOWER_OPSYS}-${OS_VERSION}-${MACHINE}-cpython-${PYTHON_VERSION}
TEST_ENV+=		PYTHONPATH=${WRKSRC:Q}/build/lib.${PYTHON_PLATFORM}

.include "../../lang/python/wheel.mk"
#.include "../../audio/libsoxr/buildlink3.mk"	# XXX: vendored
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
