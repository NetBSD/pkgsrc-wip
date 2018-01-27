# $NetBSD: Makefile,v 1.13 2012/12/27 06:09:33 othyro Exp $
#

DISTNAME=	mupen64_sound
PKGNAME=	${DISTNAME:S/_sound/-plugin-sound-1.1/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Sound plugin for mupen64 emulator

LDFLAGS+=	${LIBOSSAUDIO}
CPPFLAGS+=	-fPIC

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_FILES.dsp=	main.c
SUBST_SED.dsp=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.dsp=	Fixing harcoded audio device.

INSTALLATION_DIRS+=	share/mupen64-base/plugins

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
