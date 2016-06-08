# $NetBSD: Makefile,v 1.1 2015/08/05 21:05:13 jihbed Exp $

DISTNAME=	ionize-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ionize/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lewisamarshall.github.io/ionize/
COMMENT=	Package for calculating electrolyte properties.
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
