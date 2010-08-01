# $NetBSD: Makefile,v 1.3 2010/08/01 14:57:09 asau Exp $
#

DISTNAME=	cvxopt-1.1.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CVXOPT/
EXTRACT_SUFX=	.gz#md5=211a31494991bcd75b4790a3c5806e18

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://abel.ee.ucla.edu/cvxopt/
COMMENT=	Python software for convex optimization
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cvxopt-1.1.2/src

USE_TOOLS+=	pax
USE_LANGUAGES=	c fortran77

PYDISTUTILSPKG= yes

DOCDIR=	${PREFIX}/share/doc/py-cvxopt

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKDIR}/${DISTNAME:S/.tar//}/doc/build/html && pax -rwpe . \
		${DESTDIR}${PREFIX}/share/doc/py-cvxopt

.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
