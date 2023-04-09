# $NetBSD: Makefile,v 1.107 2023/04/07 12:58:01 mef Exp $

PKGNAME=	gnuradio-monolithic-${VERSION}
COMMENT=	GNU Software Defined Radio Monolithic version
#PLIST_MINUS=	# empty
.include	"Makefile.common"

TOOL_DEPENDS+=      tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar

#CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
#CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
#CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
#CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

#include "../../mk/oss.buildlink3.mk"
#if ${OSS_TYPE} != "none"
#CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	${PKG_SYSCONFDIR}/gr-audio-oss.conf
#LIST_SRC=	${PKGDIR}/PLIST ${PKGDIR}/PLIST.oss
#endif

# set default as minimum
# CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=      -DENABLE_GR_VIDEO_SDL=ON
CMAKE_ARGS+=      -DSDL_INCLUDE_DIR=${PREFIX}/include/SDL

# for #include <SoapySDR/Types.hpp>
#CMAKE_ARGS+=    -DCMAKE_INCLUDE_PATH=${PREFIX}/include/

# Take care CONF_FILES stuff (The same code in Nocore.mk)
#post-install:
#	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
#	      ${DESTDIR}${PREFIX}/${EGDIR}/

.include "../../ham/codec2/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
