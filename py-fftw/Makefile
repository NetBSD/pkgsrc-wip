# $NetBSD: Makefile,v 1.5 2012/10/01 23:56:16 jihbed Exp $
#

DISTNAME=	PyFFTW3-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/FFTW/fftw/S/3//}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyFFTW3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/P/PyFFTW3/
COMMENT=	Python bindings to the FFTW3 C-library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
