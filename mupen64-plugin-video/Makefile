# $NetBSD: Makefile,v 1.10 2012/12/27 06:15:04 othyro Exp $
#

DISTNAME=	tr64_oglv078_src
PKGNAME=	mupen64-plugin-video-0.78
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	OpenGL Video plugin for mupen64 emulator

CPPFLAGS+=	-fPIC
LIBS+=		${PTHREAD_LDFLAGS}

INSTALLATION_DIRS+=	share/mupen64-base/plugins

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
