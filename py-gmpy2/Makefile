# $NetBSD: Makefile,v 1.2 2015/04/14 11:56:21 thomasklausner Exp $

DISTNAME=	gmpy2-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gmpy2/}
EXTRACT_SUFX=	.zip#md5=95f008bcab6372164358123f43e3f490

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/aleaxit/gmpy/
COMMENT=	GMP/MPIR, MPFR, and MPC interface to Python 2.6+ and 3.x
LICENSE=	gnu-gpl-v3

BUILD_TARGET=	gmpy2.so

BUILDLINK_API_DEPENDS.gmp+=		gmp>=4.2.1
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.mpcomplex+=       mpcomplex>=0.8.2
.include "../../math/mpcomplex/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=    mpfr>=2.0.3
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
