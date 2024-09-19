# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:42 thomasklausner Exp $

DISTNAME=	jBessel-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jBessel/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/daron1337/jBessel
COMMENT=	Bessel functions of the first kind written in Cython
LICENSE=	modified-bsd

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
