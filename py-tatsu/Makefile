# $NetBSD$

DISTNAME=	TatSu-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/8e/88/ec6d0364c15e568bbb77e1272ce5712ce5d0ed2f6fe0f057fe2d55d13608/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/neogeny/tatsu
COMMENT=	Python parsers from grammars in a variation of EBNF
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
