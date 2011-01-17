# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:16:29 jihbed Exp $
#

DISTNAME=	ruffus-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/r/ruffus/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ruffus.org.uk/index.html
COMMENT=	Lightweight python module to run computational pipelines
LICENSE=	mit

DEPENDS+=  ${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=  ${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
