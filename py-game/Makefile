# $NetBSD: Makefile,v 1.4 2003/09/14 22:00:37 marc Exp $
#

DISTNAME=		pygame-1.5.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		devel
MASTER_SITES=		http://pygame.org/ftp/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

PYTHON_VERSIONS_ACCEPTED= 23 23pth 22 22pth

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
