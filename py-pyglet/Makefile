# $NetBSD: Makefile,v 1.1 2013/12/25 01:14:35 othyro Exp $

DISTNAME=	pyglet-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel games
MASTER_SITES=	http://pyglet.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pyglet/
COMMENT=	Object-oriented programming interface for developing games
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
