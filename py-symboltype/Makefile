# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:22:17 jihbed Exp $
#

DISTNAME=	SymbolType-1.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/S/T/t/}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SymbolType/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://peak.telecommunity.com/DevCenter/SymbolType
COMMENT=	Simple Symbol Type for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_symbols.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
