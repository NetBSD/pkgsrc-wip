# $NetBSD: Makefile,v 1.3 2004/11/08 22:57:04 thomasklausner Exp $
#

DISTNAME=	tr64_oglv078_src
PKGNAME=	mupen64-plugin-video-0.78
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	OpenGL Video plugin for mupen64 emulator

USE_BUILDLINK3=	yes
USE_X11=	yes

LIBS+=		${PTHREAD_LDFLAGS}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mupen64-base/plugins

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
