# $NetBSD: Makefile,v 1.1 2015/08/01 22:17:33 jihbed Exp $

DISTNAME=	arxiver-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arxiver/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jon--lee/arxiver
COMMENT=	Unofficial API tool for arxiv.org scientific publications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3.2:../../www/py-beautifulsoup4

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
