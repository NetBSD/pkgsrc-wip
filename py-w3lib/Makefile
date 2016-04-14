# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	w3lib-1.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI}

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://github.com/scrapy/w3lib
COMMENT=	Library of web-related functions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	35 # not yet ported as of 1.14.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
