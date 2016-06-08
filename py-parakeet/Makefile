# $NetBSD: Makefile,v 1.1 2014/05/05 23:29:11 jihbed Exp $

DISTNAME=	parakeet-0.23.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parakeet/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	${MASTER_SITE_PYPI:=p/parakeet/}
COMMENT=	Runtime compiler for numerical Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dsltools>=0.2.6:../../wip/py-dsltools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
