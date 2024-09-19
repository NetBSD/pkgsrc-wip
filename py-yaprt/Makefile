# $NetBSD: Makefile,v 1.1 2015/01/31 12:11:07 jihbed Exp $

DISTNAME=	yaprt-0.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yaprt/}

MAINTAINER=	derouiche@yahoo.com
HOMEPAGE=	https://github.com/cloudnull/yaprt.git
COMMENT=	Repository builder for python source code
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-cloudlib>=0.3.0:../../wip/py-cloudlib
.include "../../mk/bsd.pkg.mk"
