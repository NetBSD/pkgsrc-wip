# $NetBSD: Makefile,v 1.1 2017/04/14 12:10:26 leot Exp $

DISTNAME=	requests-cache-0.4.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/reclosedev/requests-cache
COMMENT=	Persistent cache for requests library
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
