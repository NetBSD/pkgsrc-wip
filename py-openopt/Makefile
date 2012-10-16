# $NetBSD: Makefile,v 1.6 2012/10/16 11:35:44 jihbed Exp $
#

VERSION=	0.37
DISTNAME=	OpenOpt
EGG_NAME=	openopt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://openopt.org/images/3/33/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://openopt.org/Welcome
COMMENT=	Python module for numerical optimization
LICENSE=	modified-bsd

USE_LANGUAGES=	fortran
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
