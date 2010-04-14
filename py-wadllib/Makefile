# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:28:45 jihbed Exp $
#

DISTNAME=	 wadllib-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	  www python
MASTER_SITES=	http://launchpad.net/wadllib/trunk/1.1.4/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/wadllib
COMMENT=	TODO: Short description of the package
LICENSE=		gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../wip/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../wip/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-lazr.uri>=1.0.2:../../wip/py-lazr.uri

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
