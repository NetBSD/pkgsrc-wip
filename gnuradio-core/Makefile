# $NetBSD: Makefile,v 1.23 2014/10/14 14:40:37 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Core part of GNU Radio, all others need this

PLIST_MINUS=	# empty
.include	"Makefile.common"

CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

# set default as minimum
CMAKE_ARGS+=	-DENABLE_DEFAULT=False

# disable/enable ALSA, see also patches/patch-gr-audio_lib_CMakeLists.txt
SUBST_CLASSES+=		alsa
SUBST_MESSAGE.alsa=	Arrange the patched line depepending on alsa is in PKG_OPTIONS or not
SUBST_FILES.alsa+=	gr-audio/lib/CMakeLists.txt
## $ALSA_ENABLED is '#' or ''
SUBST_SED.alsa=		-e 's,@@ALSA@@,${ALSA_ENABLED},'
SUBST_STAGE.alsa=	post-patch

# Take care CONF_FILES stuff (The same code in Nocore.mk)
post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
	      ${DESTDIR}${PREFIX}/${EGDIR}/

# NetBSD/amd64 7.99.1
# build/volk/lib/volk_32f_sqrt_32f_a_orc_impl.c:79:21: fatal error: orc/orc.h: No such file or directory
# NetBSD/i386 7.99.1
## ../lib/libgnuradio-runtime.so.3.7.5: undefined reference to `shm_unlink'
## ../lib/libgnuradio-runtime.so.3.7.5: undefined reference to `shm_open'
.include	"../../mk/bsd.pkg.mk"
