# $NetBSD: Makefile,v 1.11 2004/03/07 23:22:11 blef Exp $
#

DISTNAME=	MuSE-0.8.1
PKGNAME=	${DISTNAME:S/MuSE/muse/}
CATEGORIES=	audio
MASTER_SITES=	http://muse.dyne.org/releases/ \
		http://savannah.nongnu.org/download/muse/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://muse.dyne.org/
COMMENT=	Multiple Streaming Engine

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_OSS=	YES
USE_X11=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MUSE_USES_RUBIK

.if defined(MUSE_USES_RUBIK) && !empty(MUSE_USES_RUBIK:M[yY][eE][sS])
USE_NCURSES=    YES
CONFIGURE_ARGS=	--with-rubik
.include "../../devel/ncurses/buildlink3.mk"
.endif

CPPFLAGS=	-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
