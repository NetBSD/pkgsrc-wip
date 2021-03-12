# $NetBSD$

DISTNAME=	wurst-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wurst/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cmutel/wurst
COMMENT=	Linking and modifying industrial ecology models
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-constructive-geometries>=0:../../wip/py-constructive-geometries
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-json-logger>=2.0.1:../../wip/py-json-logger
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.11.1:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.56.2:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.12.1:../../devel/py-wrapt


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
