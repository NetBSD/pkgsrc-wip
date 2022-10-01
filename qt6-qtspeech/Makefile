# $NetBSD$

DISTNAME=	qtspeech-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtspeech-${QTVERSION}
COMMENT=	Qt6 module for text to speech
CATEGORIES=	audio
LICENSE=	gnu-gpl-v3

CONFIGURE_ARGS+=	-no-flite-alsa

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6TextToSpeech.pc

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../audio/flite/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../wip/qt6-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
