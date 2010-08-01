# $NetBSD: Makefile,v 1.22 2010/08/01 14:57:08 asau Exp $

DISTNAME=	avifile-0.7-0.7.45
PKGNAME=	avifile-devel-0.7.45
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=avifile/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://avifile.sourceforge.net/
COMMENT=	MPEG-4 (DivX) video player library

PKG_DESTDIR_SUPPORT=	user-destdir

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	win32-codecs>=010122:../../multimedia/win32-codecs
.endif

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++ fortran77

PKGCONFIG_OVERRIDE+=	avifile.pc.in

PLIST_VARS=	ac3pass ffmpeg jpeg mad lame qt v4l vidix vorbis win32 xvid

.include "options.mk"

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-xvid
CONFIGURE_ARGS+=	--disable-divx4
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-win32
CONFIGURE_ARGS+=	--with-win32-path=${LOCALBASE:Q}/lib/win32
PLIST.win32=		yes
.else
CONFIGURE_ARGS+=	--disable-win32
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-ffmpeg
PLIST.ffmpeg=		yes
.else
CONFIGURE_ARGS+=	--disable-x86opt
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-v4l
PLIST.v4l=		yes
.else
CONFIGURE_ARGS+=	--disable-v4l
SUBST_CLASSES+=		v4l
SUBST_STAGE.v4l=	pre-configure
SUBST_MESSAGE.v4l=	do not support v4l, so do not build qtvidcap
SUBST_FILES.v4l=	samples/Makefile.in
SUBST_SED.v4l=		-E -e 's|^(SUBDIRS.+)qtvidcap|\1|'

SUBST_CLASSES+=		v4lman
SUBST_STAGE.v4lman=	pre-configure
SUBST_MESSAGE.v4lman=	do not install man page for v4l
SUBST_FILES.v4lman=	doc/Makefile.in
SUBST_SED.v4lman=	-e 's|kv4lsetup.1||'
SUBST_SED.v4lman+=	-e 's|avirec.1||'
.endif

.if ${MACHINE_ARCH} == "i386" && (${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD")
CONFIGURE_ARGS+=	--enable-vidix
PLIST.vidix=		yes
.else
CONFIGURE_ARGS+=	--disable-vidix
.endif

SUBST_CLASSES+=		pkgname
SUBST_STAGE.pkgname=	pre-configure
SUBST_MESSAGE.pkgname=	use pkgname without version to build dir name
SUBST_FILES.pkgname=	configure
SUBST_SED.pkgname=	-E -e 's|(PACKAGE[:space:]*=[:space:]*avifile).*|\1|'

SUBST_CLASSES+=		docpath
SUBST_STAGE.docpath=	pre-configure
SUBST_MESSAGE.docpath=	fix document path
SUBST_FILES.docpath=	Makefile.in doc/Makefile.in doc/avicap/Makefile.in \
			plugins/libac3pass/Makefile.in
SUBST_SED.docpath=	-E -e 's|[(]datadir[)]/[$$][(]PACKAGE[)]/doc|(datadir)/doc/$$(PACKAGE)|'

. include "../../mk/oss.buildlink3.mk"

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	/dev/dsp to ${DEVOSSSOUND}
SUBST_FILES.dsp=	ffmpeg/libavformat/audio.c \
			lib/aviplay/OssAudioRenderer.cpp \
			samples/qtvidcap/avirec.cpp \
			samples/qtvidcap/capproc.cpp \
			samples/qtvidcap/dsp.cpp \
			samples/qtvidcap/dsp.h \
			samples/qtvidcap/vidconf.cpp \
			samples/qtvidcap/vidconf_p.cpp
SUBST_SED.dsp=		-e 's|/dev/dsp|${DEVOSSSOUND}|'

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv:Q}
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
