# $NetBSD: Makefile,v 1.6 2004/03/06 17:15:52 mpasternak Exp $
#

DISTNAME=		pygame-1.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK3=		yes

PYTHON_VERSIONS_ACCEPTED= 23 23pth 22 22pth

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/smpeg/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
