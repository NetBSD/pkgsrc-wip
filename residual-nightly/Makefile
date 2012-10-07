# $NetBSD: Makefile,v 1.4 2012/10/07 14:53:43 asau Exp $

DISTNAME=	residual-${SCM_VER}
CATEGORIES=	games

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://residual.sourceforge.net/
COMMENT=	Lucas Arts' LUA-based 3D adventure engine

RESTRICTED=	changes daily
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ARGS+=--mandir=${PREFIX}/${PKGMANDIR}
WRKSRC=		${WRKDIR}/residual

SVN_REPOSITORIES=	residual
SVN_TAG=		{${SCM_TAG}}
SVN_CERTS=		files/1559baa475cf8c004d9ce6b7ca4cae6b
SVN_ROOT.residual=	https://residual.svn.sourceforge.net/svnroot/residual/residual/trunk
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
