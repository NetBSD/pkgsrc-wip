# $NetBSD: Makefile,v 1.1 2014/08/06 21:34:53 jihbed Exp $

DISTNAME=	Fortpy-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Fortpy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rosenbrockc/fortpy
COMMENT=	Fortran Parsing, Unit Testing and Intellisense
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.14.0:../../security/py-paramiko
#DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.0:../../time/py-dateutil2

USE_LANGUAGES=	# none

PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/fortpy/scripts/compare.py ${WRKSRC}/fortpy/scripts/compare.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/fortpy/scripts/convert.py ${WRKSRC}/fortpy/scripts/convert.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/fortpy/scripts/runtests.py ${WRKSRC}/fortpy/scripts/runtests.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
