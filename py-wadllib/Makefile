# $NetBSD: Makefile,v 1.5 2012/10/14 22:09:25 thomasklausner Exp $
#

DISTNAME=	wadllib-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://launchpad.net/wadllib/trunk/1.1.4/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/wadllib
COMMENT=	Library for navigating WADL files
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-lazr.uri>=1.0.2:../../wip/py-lazr.uri

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
