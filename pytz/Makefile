# $NetBSD: Makefile,v 1.2 2008/01/23 07:51:48 obache Exp $
#

DISTNAME=	pytz-2007k
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytz/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pypi.python.org/packages/source/p/pytz/
COMMENT=	World Timezone Definitions for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
