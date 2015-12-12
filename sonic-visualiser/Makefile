# $NetBSD$

DISTNAME=	sonic-visualiser-2.5
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/1675/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sonicvisualiser.org/
COMMENT=	Application for viewing and analysing music audio files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	dataquay/deploy/dataquay.pc.in

CONFIGURE_ARGS+=	QTDIR=${QTDIR}

.include "../../textproc/sord/buildlink3.mk"
.include "../../wip/rubberband/buildlink3.mk"
.include "../../wip/vamp-plugin-sdk/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
