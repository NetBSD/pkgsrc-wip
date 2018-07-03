# $NetBSD: Makefile,v 1.2 2015/02/20 16:28:54 jihbed Exp $

DISTNAME=	moksha.hub-1.4.4
 PKGNAME=	${PYPKGPREFIX}-moksha-hub-1.4.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moksha.hub/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://moksha.fedorahosted.org
COMMENT=	Hub components for Moksha
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.4.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-txWS>=0.9.1:../../wip/py-txWS
DEPENDS+=	${PYPKGPREFIX}-txZMQ>=0.7.3:../../wip/py-txZMQ
DEPENDS+=	${PYPKGPREFIX}-moksha-common>=1.2.3:../../wip/py-moksha-common

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-moksha-common

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
