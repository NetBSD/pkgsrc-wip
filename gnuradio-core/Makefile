# $NetBSD: Makefile,v 1.17 2014/09/18 09:52:22 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Runtime system and DSP blocks for GNU Radio

PLIST_MINUS=	# empty
.include	"../../wip/gnuradio-core/Makefile.common"

BUILD_DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
# gnuradio-companion wants:
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
	      ${DESTDIR}${PREFIX}/${EGDIR}/

.include	"../../mk/bsd.pkg.mk"
