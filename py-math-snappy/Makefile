# $NetBSD: Makefile,v 1.2 2015/01/10 20:41:36 thomasklausner Exp $

VERSION=	2.2
DISTNAME=	SnapPy
PKGNAME=	${PYPKGPREFIX}-math-snappy-${VERSION}
EGG_NAME=	${DISTNAME:tl}-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://snappy.computop.org/get/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://snappy.computop.org/get/
COMMENT=	Program for studying the topology and geometry of 3-manifolds
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.2:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
