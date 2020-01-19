# $NetBSD: Makefile,v 1.6 2012/11/12 16:26:47 othyro Exp $
#

DISTNAME=	fwrap-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwrap/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://fwrap.sourceforge.net/
COMMENT=	Tool to wrap Fortran 77/90/95 code in C, Cython & Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtest.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
