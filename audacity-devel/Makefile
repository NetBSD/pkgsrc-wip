# $NetBSD: Makefile,v 1.15 2013/01/13 23:28:28 makoto Exp $

DISTNAME=		audacity-minsrc-2.0.2
PKGNAME=		${DISTNAME:S/-minsrc-/-/}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=audacity/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://audacity.sourceforge.net/
COMMENT=		Audio editor

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME:S/-min/-/}

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake msgfmt pkg-config zip:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
# =system means 'use pkgsrc instead of included in portaudio'
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3=system
CONFIGURE_ARGS+=	--with-libflac=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-vorbis=system
# 20111121 version of portaudio is missing 'Pa_GetStreamHostApiType'
#.include "../../audio/portaudio-devel/buildlink3.mk"
CONFIGURE_ENV+=		WX_CONFIG=${PREFIX}/bin/wx-config

CONFIG_GUESS_OVERRIDE=		\
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE=		\
	config.sub */config.sub */*/config.sub */*/*/config.sub

SUBST_CLASSES+=		clang
SUBST_STAGE.clang=	post-patch
SUBST_MESSAGE.clang=	Fix linking problem for clang
SUBST_FILES.clang=	lib-src/libnyquist/nyquist/ffts/src/fftlib.c
SUBST_SED.clang=	-e 's|inline void|static inline void|'

PTHREAD_AUTO_VARS=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
# 20111121 version is missing 'Pa_GetStreamHostApiType'
#.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
