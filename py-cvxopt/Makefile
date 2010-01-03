# $NetBSD: Makefile,v 1.1.1.1 2010/01/03 09:19:28 jihbed Exp $
#

DISTNAME=	cvxopt-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://abel.ee.ucla.edu/src/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://abel.ee.ucla.edu/cvxopt/
COMMENT=	Python software for convex optimization
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_TOOLS+=	pax
USE_LANGUAGES=	c fortran
PYDISTUTILSPKG= yes

PYTHON_VERSIONS_ACCEPTED= 25

DOCDIR=	${PREFIX}/share/doc/py-cvxopt

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/doc/html && pax -rwpe . \
		${DESTDIR}${PREFIX}/share/doc/py-cvxopt

.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
