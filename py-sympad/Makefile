# $NetBSD$

DISTNAME=	sympad-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/7f/70/2bdc7d3c7d20c822f0c1bdd3fcda4f4d5f7fc5eb1f108b2574e776d57287/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Pristine-Cat/sympad
COMMENT=	Graphical symbolic math calculator / scratchpad using SymPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
