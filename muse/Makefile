# $NetBSD: Makefile,v 1.4 2003/06/02 16:40:41 xtraeme Exp $
#

DISTNAME=	MuSE-0.8.1
PKGNAME=	${DISTNAME:S/MuSE/muse/}
CATEGORIES=	audio
MASTER_SITES=	http://muse.dyne.org/releases/ \
		http://savannah.nongnu.org/download/muse/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://muse.dyne.org/
COMMENT=	Multiple Streaming Engine

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_OSS=	YES
USE_GMAKE=	YES
USE_NCURSES=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-rubik

CPPFLAGS=	-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
