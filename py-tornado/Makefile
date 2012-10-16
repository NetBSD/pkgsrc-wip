# $NetBSD: Makefile,v 1.3 2012/10/16 08:53:03 jihbed Exp $
#

DISTNAME=	tornado-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://github.com/downloads/facebook/tornado/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.tornadoweb.org/
COMMENT=	Open source web server and tools that power FriendFeed
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.3:../../databases/py-mysqldb
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.6.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-curl>=7.19.0:../../www/py-curl

PYTHON_VERSIONS_INCLUDE_3X=yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
