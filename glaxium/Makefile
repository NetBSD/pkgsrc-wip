# $NetBSD: Makefile,v 1.2 2003/08/28 09:48:45 xtraeme Exp $
#

DISTNAME=	glaxium_0.5
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xhosxe.free.fr/glaxium/
COMMENT=	Space-ship OpenGL shoot them up

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GMAKE=		yes

MESA_REQD=		5.0.1
ALL_TARGET=		glaxium

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
