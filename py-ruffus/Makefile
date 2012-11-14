# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:16 othyro Exp $
#

DISTNAME=	ruffus-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/r/ruffus/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ruffus.org.uk/index.html
COMMENT=	Lightweight python module to run computational pipelines
LICENSE=	mit

DEPENDS+=  ${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=  ${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
