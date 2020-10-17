# $NetBSD$

DISTNAME=	pygame_geometry-0.1.2
PKGNAME=	${PYPKGPREFIX}-game-geometry-0.1.2
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/cf/8b/cf1b2b409fe5ee52e952f638b1b5ce87dc2e6929b1cc79e6f17afd473132/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MarcPartensky/Pygame-Geometry
COMMENT=	Geometry environment for pygame
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-game>=1.9.6:../../devel/py-game

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
