# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	w3lib-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/w/w3lib/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://github.com/scrapy/w3lib
COMMENT=	Library of web-related functions
LICENSE=	mit

REPLACE_PYTHON=	${WRKSRC}/*.py

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
