# $NetBSD: Makefile,v 1.3 2014/12/30 17:09:59 thomasklausner Exp $

DISTNAME=	acq4-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acq4/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/a/acq4/
COMMENT=	Neurophysiology acquisition and analysis platform
LICENSE =	mit

#DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.2.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
