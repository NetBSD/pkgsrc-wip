# $NetBSD$

DISTNAME=	sip-${PKGVERSION_NOREV}
PKGNAME=        ${PYPKGPREFIX}-sip6-6.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://pypi.org/project/sip/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR modified-bsd


DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
