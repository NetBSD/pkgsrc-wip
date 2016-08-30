# $NetBSD: Makefile,v 1.13 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	python-djvulibre-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	graphics textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-djvulibre/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/python-djvulibre
COMMENT=	Python bindings for the DjVuLibre library
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c

# used by setup.py and during build
pre-build:
	mkdir -p ${BUILDLINK_DIR}/bin
	ln -s ${PYTHONBIN} ${BUILDLINK_DIR}/bin/python

.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.20
.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
