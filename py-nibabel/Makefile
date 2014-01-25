# $NetBSD: Makefile,v 1.7 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	nibabel-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://pypi.python.org/packages/source/n/nibabel/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nipy.org/nibabel
COMMENT=	Access a multitude of neuroimaging data formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.7:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-dicom>=0.9.8:../../wip/py-dicom

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-fuse-bindings

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
