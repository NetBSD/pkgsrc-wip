# $NetBSD: Makefile,v 1.2 2003/07/13 09:29:45 marc Exp $
#

DISTNAME=		pygame-1.5.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		devel
MASTER_SITES=		http://pygam.org/ftp/

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://pygame.org/
COMMENT=		Set of Python modules designed for writing games

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

PYTHON_VERSIONS_ACCEPTED= 22 22pth

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
