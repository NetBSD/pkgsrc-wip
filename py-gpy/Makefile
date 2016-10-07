# $NetBSD$

DISTNAME=	GPy-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/a6/d8/de80ebdc3e88da66512b3ad1b7b4655ba82300ce77beab9a0c479d9c24d1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sheffieldml.github.com/GPy/
COMMENT=	The Gaussian Process Toolbox
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/GPy-1.5.5

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
