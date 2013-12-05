# $NetBSD: Makefile,v 1.4 2013/12/05 15:22:34 jihbed Exp $

DISTNAME=	mpop-v1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/m/mpop/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mraspaud/mpop
COMMENT=	Meteorological post processing package
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
