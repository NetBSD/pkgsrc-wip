# $NetBSD: Makefile,v 1.2 2012/01/30 02:47:38 noud4 Exp $
#

DISTNAME=	PyFFTW3-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/FFTW/fftw/S/3//}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyFFTW3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/P/PyFFTW3/
COMMENT=	Python bindings to the FFTW3 C-library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

WRKSRC=		${WRKDIR}/PyFFTW3-0.2
USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-fftw

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/test_fftw3.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/py-fftw
.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
