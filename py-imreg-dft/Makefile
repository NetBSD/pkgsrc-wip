# $NetBSD: Makefile,v 1.1 2015/02/21 16:46:10 jihbed Exp $

DISTNAME=	imreg_dft-1.0.2
PKGNAME=	${PYPKGPREFIX}-imreg-dft-1.0.2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imreg_dft/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/matejak/imreg_dft
COMMENT=	Image registration utility using discrete Fourier transform
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.7.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
