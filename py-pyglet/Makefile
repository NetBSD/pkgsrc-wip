# $NetBSD$

DISTNAME=	pyglet-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel games
#MASTER_SITES=	${MASTER_SITE_PYPI:=c/pyglet/}
MASTER_SITES=	-https://files.pythonhosted.org/packages/9b/4b/6b023c829406f91787a81b7234d6d798e5da356d8a2ef18e64b27f89fc13/pyglet-1.3.2.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pyglet/
COMMENT=	Object-oriented programming interface for developing games
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

#PYDISTUTILSPKG=	yes

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#.include "../../lang/python/application.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
