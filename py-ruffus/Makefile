# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	ruffus-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruffus/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ruffus.org.uk/index.html
COMMENT=	Lightweight python module to run computational pipelines
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
