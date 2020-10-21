# $NetBSD$

DISTNAME=	CythonGSL-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CythonGSL/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/twiecki/CythonGSL
COMMENT=	Cython declarations for the Gnu Scientific Library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup_test.py
	
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
