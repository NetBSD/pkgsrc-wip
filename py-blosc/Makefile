# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:20 thomasklausner Exp $

DISTNAME=	blosc-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blosc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://python-blosc.blosc.org/
COMMENT=	Python wrapper for the Blosc compression library
LICENSE=	modified-bsd

USE_LANGUAGES=	c

MAKE_ENV+=	BLOSC_DIR=${BUILDLINK_PREFIX.blosc}
PYDISTUTILSPKG=	yes

.include "../../devel/blosc/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
