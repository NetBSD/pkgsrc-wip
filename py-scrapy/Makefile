# $NetBSD: Makefile,v 1.4 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	Scrapy-0.14.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/S/Scrapy/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://scrapy.org/
COMMENT=	Python web scraping framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.0:../../wip/py-w3lib
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.1:../../textproc/py-lxml

REPLACE_PYTHON=	${WRKSRC}/*.py

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
