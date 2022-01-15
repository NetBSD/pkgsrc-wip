# $NetBSD$

DISTNAME=	PyQt-builder-${PKGVERSION_NOREV}
PKGNAME=        ${PYPKGPREFIX}-qt5-builder-1.12.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt-builder/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://pypi.org/project/PyQt-builder/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR modified-bsd


DEPENDS+=	${PYPKGPREFIX}-sip6>=6:../../wip/py-sip6

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pyqtbuild/bundle && rm -r dlls

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
