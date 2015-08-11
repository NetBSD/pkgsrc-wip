# $NetBSD: Makefile,v 1.6 2015/08/11 23:01:32 jihbed Exp $

DISTNAME=	astropy-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	https://pypi.python.org/packages/source/a/astropy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.astropy.org/
COMMENT=	Community-developed python astronomy tools
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/astropy-1.0.4

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cextern/wcslib/wcslib.pc.in
PKGCONFIG_OVERRIDE+=	cextern/expat/expat.pc.in

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
