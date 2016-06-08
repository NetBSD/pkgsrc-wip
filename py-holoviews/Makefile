# $NetBSD: Makefile,v 1.1 2015/07/07 01:22:57 jihbed Exp $

DISTNAME=	holoviews-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_PYPI:=h/holoviews/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ioam.github.com/holoviews/
COMMENT=	Declarative data structures for building complex visualizations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-param>=1.3.2:../../wip/py-param

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
