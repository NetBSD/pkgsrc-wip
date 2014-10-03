# $NetBSD: Makefile,v 1.21 2014/10/03 03:39:58 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Runtime system and DSP blocks for GNU Radio

PLIST_MINUS=	# empty
.include	"../../wip/gnuradio-core/Makefile.common"

CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
CONF_FILES+=	${EGDIR}/gr-audio-alsa.conf	${PKG_SYSCONFDIR}/gr-audio-alsa.conf
CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

# set default as minimum
CMAKE_ARGS+=	-DENABLE_DEFAULT=False

# Take care CONF_FILES stuff (The same code in Nocore.mk)
post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
	      ${DESTDIR}${PREFIX}/${EGDIR}/

# NetBSD/amd64 7.99.1
# build/volk/lib/volk_32f_sqrt_32f_a_orc_impl.c:79:21: fatal error: orc/orc.h: No such file or directory
# NetBSD/i386 7.99.1 
## ../lib/libgnuradio-runtime.so.3.7.5: undefined reference to `shm_unlink'
## ../lib/libgnuradio-runtime.so.3.7.5: undefined reference to `shm_open'
.include	"../../devel/orc/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
