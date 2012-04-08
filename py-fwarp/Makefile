# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:46 thomasklausner Exp $
#

DISTNAME=	fwrap-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/fwrap/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fwrap.sourceforge.net/
COMMENT=	Tool to wrap Fortran 77/90/95 code in C, Cython & Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtest.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
