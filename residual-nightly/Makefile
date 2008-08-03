# $NetBSD: Makefile,v 1.1.1.1 2008/08/03 15:49:13 dillo Exp $

DISTNAME=	residual-${SCM_VER}
CATEGORIES=	games

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	Lucas Arts' LUA-based 3D adventure engine

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	changes daily
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ARGS+=--mandir=${PREFIX}/${PKGMANDIR}
USE_DIRS+=	xdg-1.1
WRKSRC=		${WRKDIR}/residual

SVN_REPOSITORIES=	residual
SVN_TAG=		{${SCM_TAG}}
SVN_CERTS=		files/dbd39a6ed632407eb1510e5009956117
SVN_ROOT.residual=	https://scummvm.svn.sourceforge.net/svnroot/scummvm/residual/trunk
SVN_MODULE.residual=	residual

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
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
