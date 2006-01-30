# $NetBSD: Makefile,v 1.1.1.1 2006/01/30 01:26:28 lsed Exp $

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}

COMMENT=	Software-only MPEG-1/2/4 video decoder

.include "../../wip/mplayer-share/Makefile.common"

CVS_REPOSITORIES=	mplayer ffmpeg
CVS_ROOT.mplayer=	:pserver:anonymous:@mplayerhq.hu:/cvsroot/mplayer
CVS_MODULE.mplayer=	main
CVS_ROOT.ffmpeg=	:pserver:anonymous:@mplayerhq.hu:/cvsroot/ffmpeg
CVS_MODULE.ffmpeg=	ffmpeg

.include "../../wip/mk/cvs-package.mk"

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

INSTALLATION_DIRS+=	bin

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

do-fetch:

post-extract:
	${MV} ${WRKDIR}/ffmpeg/libav* ${WRKDIR}/mplayer/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../wip/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"

.include "../../wip/mplayer-share/Makefile.cflags"
