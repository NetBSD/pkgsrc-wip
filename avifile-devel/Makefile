# $NetBSD: Makefile,v 1.3 2005/04/26 10:54:12 obache Exp $

DISTNAME=	avifile-0.7-0.7.43
PKGNAME=	avifile-devel-0.7.43
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=avifile/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://avifile.sourceforge.net/
COMMENT=	MPEG-4 (DivX) video player library

.if ${MACHINE_ARCH} == "i386"
DEPENDS=	win32-codecs>=010122:../../multimedia/win32-codecs
.endif

USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_LANGUAGE+=		c c++ fortran

.include "options.mk"

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-xvid
CONFIGURE_ARGS+=	--disable-divx4
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-win32
CONFIGURE_ARGS+=	--with-win32-path="${LOCALBASE}/lib/win32"
PLIST_SUBST+=	WIN32_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-win32
PLIST_SUBST+=	WIN32_COMMENT="@comment "
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
BUILD_DEFS+=            USE_MMX
. if !empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-x86opt
. else
CONFIGURE_ARGS+=	--disable-x86opt
. endif
CONFIGURE_ARGS+=	--enable-ffmpeg
PLIST_SUBST+=	FFMPEG_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-x86opt
CONFIGURE_ARGS+=	--disalbe-ffmpeg
PLIST_SUBST+=	FFMPEG_COMMENT="@comment "
.endif
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-v4l
PLIST_SUBST+=	V4L_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-v4l
PLIST_SUBST+=	V4L_COMMENT="@comment "
SUBST_CLASSES+=		v4l
SUBST_STAGE.v4l=	pre-configure
SUBST_MESSAGE.v4l=	do not support v4l, so do not build qtvidcap
SUBST_FILES.v4l=	samples/Makefile.in
SUBST_SED.v4l=		-E -e 's|^(SUBDIRS.+)qtvidcap|\1|'
SUBST_CLASSES+=		v4lman
SUBST_STAGE.v4lman=	pre-configure
SUBST_MESSAGE.v4lman=	do not install man page for v4l
SUBST_FILES.v4lman=	doc/Makefile.in
SUBST_SED.v4lman=	-e 's|kv4lsetup.1||' -e 's|avirec.1||'
.endif

.if ${MACHINE_ARCH} == "i386" && (${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD")
CONFIGURE_ARGS+=	--enable-vidix
PLIST_SUBST+=		VIDIX_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-vidix
PLIST_SUBST+=		VIDIX_COMMENT="@comment "
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

. include "../../mk/ossaudio.buildlink3.mk"
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
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
