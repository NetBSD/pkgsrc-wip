# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:55 shattered Exp $

DISTNAME=	scummvm-${SCM_VER}
CATEGORIES=	games
MASTER_SITES=	http://scummvm.sourceforge.net/daily/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

NO_CHECKSUM=	yes
NO_SRC_ON_FTP=	# changes daily
NO_SRC_ON_CDROM=# changes daily
USE_TOOLS+=	gmake
USE_X11=	yes
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE}
CONFIGURE_ARGS+=--enable-lure
CONFIGURE_ARGS+=--enable-agi
USE_DIRS+=	xdg-1.1
WRKSRC=		${WRKDIR}/scummvm

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

# tar balls get created about 0545.  Give it some room and subtract 7h
YESTERDAY!=	expr `date +%s` - 25200
SCM_VER!=	${DATE} -r ${YESTERDAY} +%Y%m%d

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
