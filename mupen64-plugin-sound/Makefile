# $NetBSD: Makefile,v 1.1.1.1 2004/04/16 22:30:19 xtraeme Exp $
#

DISTNAME=	mupen64_sound
PKGNAME=	${DISTNAME:S/_sound/-plugin-sound-1.1/}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Sound plugin for mupen64 emulator

USE_BUILDLINK3=	yes
USE_X11=	yes

LDFLAGS+=	${LIBOSSAUDIO}

SUBST_CLASSES=	    dsp
SUBST_STAGE.dsp=    post-patch
SUBST_FILES.dsp=    main.c
SUBST_SED.dsp=	    -e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.dsp=  "Fixing harcoded audio device."

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
