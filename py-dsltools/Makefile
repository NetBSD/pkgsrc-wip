# $NetBSD: Makefile,v 1.1 2014/05/05 23:21:54 jihbed Exp $

DISTNAME=	dsltools-0.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dsltools/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/iskandr/dsltools
COMMENT=	Creating and traversing recursively nested data structures
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
