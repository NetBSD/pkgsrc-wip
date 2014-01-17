# $NetBSD: Makefile,v 1.1 2014/01/17 21:17:14 jihbed Exp $

DISTNAME=	acq4-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/a/acq4/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/a/acq4/
COMMENT=	Neurophysiology acquisition and analysis platform
LICENSE = mit

#DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.2.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../wip/py-h5py

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
