# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 16:31:24 xtraeme Exp $
#

DISTNAME=		beep-media-player-1.0.0-pre5
CATEGORIES=		audio
MASTER_SITES=		http://linux-media.net/beep/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://linux-media.net/beep/
COMMENT=		Beep Media Player based on XMMS

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
FILESDIR=		${.CURDIR}/../../audio/xmms/files

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-one-plugin-dir
CONFIGURE_ARGS+=	--disable-user-plugin-dir
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ARGS+=	--disable-alsa

PTHREAD_OPTS+=		require

.if ${OPSYS} == "NetBSD"
RAWPART!=		/sbin/sysctl -n kern.rawpartition | tr 0-9 a-j
CONFIGURE_ARGS+=	--with-dev-dsp=${DEVOSSSOUND}           \
			--with-cdda-device=/dev/rcd0${RAWPART}  \
			--with-cdda-dir=/cdrom/
.  if ${MACHINE_ARCH} == "i386"
post-patch:
.    if ${OBJECT_FMT} == "a.out"
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/Input/mpg123/decode_i586.s
.    endif
	cd ${WRKSRC}/Input/mpg123 && \
	${MV} decode_i586.s decode_i586.s.orig && \
	${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s
.  endif
.endif

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
