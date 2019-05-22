# $NetBSD: Makefile,v 1.26 2012/12/12 10:44:38 thomasklausner Exp $

DISTNAME=	scummvm-${SCM_VER}
CATEGORIES=	games
GIT_REPO=	git@github.com:scummvm/scummvm.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion
LICENSE=	gnu-gpl-v2

NO_SRC_ON_FTP=		# changes daily
NO_SRC_ON_CDROM=	# changes daily
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "options.mk"

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
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
