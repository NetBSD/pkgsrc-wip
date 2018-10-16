# $NetBSD: Makefile,v 1.1 2015/01/31 11:52:04 jihbed Exp $

DISTNAME=	cloudlib-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloudlib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cloudnull/cloudlib
COMMENT=	General purpose library for in application use
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ptable>=0.7.2:../../textproc/py-ptable

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
