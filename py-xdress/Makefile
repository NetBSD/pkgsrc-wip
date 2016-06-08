# $NetBSD: Makefile,v 1.1 2013/09/07 18:56:46 jihbed Exp $

DISTNAME=	xdress-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdress/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://xdress.org/
COMMENT=	Automatic wrapper generator for C/C++ written in pure Python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/xdress-0.2
USE_LANGUAGES=	# none

#DEPENDS+=	${PYPKGPREFIX}-gccxml>=1.0.0:../../wip/py-gccxml

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
