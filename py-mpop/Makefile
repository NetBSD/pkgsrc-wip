# $NetBSD: Makefile,v 1.5 2014/09/10 09:12:46 thomasklausner Exp $

DISTNAME=	mpop-v1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-v/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpop/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mraspaud/mpop
COMMENT=	Meteorological post processing package
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
