# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	Scrapy-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://scrapy.org/
COMMENT=	Python web scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-queuelib-[0-9]*:../../wip/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=10.0.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.8.0:../../wip/py-w3lib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.0.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
