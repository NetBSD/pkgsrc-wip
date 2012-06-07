# $NetBSD: Makefile,v 1.1.1.1 2012/06/07 18:11:03 slitvinov Exp $
#

DISTNAME=	Scrapy-0.14.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/S/Scrapy/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://scrapy.org/
COMMENT=	Python web scraping framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.0:../../wip/py-w3lib

REPLACE_PYTHON=	${WRKSRC}/*.py

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
