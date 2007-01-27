# $NetBSD: Makefile,v 1.8 2007/01/27 15:34:29 dillo Exp $

PKGNAME=	scummvm-${SCM_VER}
CATEGORIES=	games

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

NO_CHECKSUM=	yes
NO_SRC_ON_FTP=	# changes daily
NO_SRC_ON_CDROM=# changes daily
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE}
CONFIGURE_ARGS+=--enable-lure
CONFIGURE_ARGS+=--enable-parallaction
USE_DIRS+=	xdg-1.1
WRKSRC=		${WRKDIR}/scummvm

SVN_REPOSITORIES=	scummvm
SVN_TAG=		{${SCM_TAG}}
SVN_CERTS=		files/dbd39a6ed632407eb1510e5009956117
SVN_ROOT.scummvm=	https://scummvm.svn.sourceforge.net/svnroot/scummvm/scummvm/trunk
SVN_MODULE.scummvm=	scummvm

.include "../../wip/mk/svn-package.mk"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

YESTERDAY!=	expr `date +%s` - 86399
SCM_VER!=	${DATE} -r ${YESTERDAY} +%Y%m%d
SCM_TAG!=	${DATE} +%Y%m%d

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
