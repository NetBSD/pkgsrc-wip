# $NetBSD: Makefile,v 1.10 2004/01/25 02:32:49 grantbeattie Exp $
#

DISTNAME=	MuSE-0.8.1
PKGNAME=	${DISTNAME:S/MuSE/muse/}
CATEGORIES=	audio
MASTER_SITES=	http://muse.dyne.org/releases/ \
		http://savannah.nongnu.org/download/muse/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://muse.dyne.org/
COMMENT=	Multiple Streaming Engine

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_OSS=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MUSE_USES_RUBIK

.if defined(MUSE_USES_RUBIK) && !empty(MUSE_USES_RUBIK:M[yY][eE][sS])
USE_NCURSES=    YES
CONFIGURE_ARGS=	--with-rubik
.include "../../devel/ncurses/buildlink2.mk"
.endif

CPPFLAGS=	-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
