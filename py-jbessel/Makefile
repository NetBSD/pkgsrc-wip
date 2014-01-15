# $NetBSD: Makefile,v 1.1 2014/01/15 20:55:41 jihbed Exp $

DISTNAME=	jBessel-0.1.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/j/jBessel/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/daron1337/jBessel
COMMENT=	Bessel functions of the first kind written in Cython
LICENSE=	modified-bsd

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
