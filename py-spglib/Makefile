# $NetBSD$

DISTNAME=	spglib-1.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://files.pythonhosted.org/packages/c4/a6/6cc744b15a1a68084f87a7f96b60d5a8a0af53dbbf7dccb1ae4046ece952/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://spglib.github.io/spglib/
COMMENT=	Python bindings for finding and handling crystal symmetries
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
