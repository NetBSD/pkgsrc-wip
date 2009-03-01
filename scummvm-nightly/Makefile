# $NetBSD: Makefile,v 1.18 2009/03/01 15:33:47 dillo Exp $

DISTNAME=	scummvm-${SCM_VER}
CATEGORIES=	games

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

NO_SRC_ON_FTP=	# changes daily
NO_SRC_ON_CDROM=# changes daily
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${LOCALBASE}
CONFIGURE_ARGS+=--mandir=${LOCALBASE}/${PKGMANDIR}
USE_DIRS+=	xdg-1.1
WRKSRC=		${WRKDIR}/scummvm

.include "options.mk"

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

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
