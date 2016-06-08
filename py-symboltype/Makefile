# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	SymbolType-1.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/S/T/t/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SymbolType/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://peak.telecommunity.com/DevCenter/SymbolType
COMMENT=	Simple Symbol Type for Python

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_symbols.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
