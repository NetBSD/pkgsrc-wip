# $NetBSD$

VERSION=	2.11.5

DISTNAME=	gqrx-sdr-${VERSION}-src
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=csete/}
GITHUB_PROJECT=	gqrx
GITHUB_RELEASE=	v${VERSION}
EXTRACT_SUFX=	.tar.xz
PKGNAME=	gqrx-${VERSION}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://gqrx.dk/
COMMENT=	SDR GUI using GNU Radio
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/gqrx-sdr-${VERSION}
USE_CMAKE=	yes
#CMAKE_ARGS+=	-DTRY_SHM_VMCIRCBUF=ON
USE_LANGUAGES=	c c++

## These dependencies are organized according to upstream's README
## at https://github.com/csete/gqrx rather than alphabetically.

# upstream's README.md does not document a dependency on boost libraries,
# probably because gnuradio-core depends on boost, but there is one.
.include "../../devel/boost-libs/buildlink3.mk"

# Upstream documents needing multiple gnuradio blocks.  These do not
# obviously correspond to pkgsrc split package names, so we list the
# required blocks ahead of each gnuradio split package.
# core has runtime, analog, audio, blocks, fft, filter, pmt
.include "../../ham/gnuradio-core/buildlink3.mk"
# digital has digital
.include "../../ham/gnuradio-digital/buildlink3.mk"

# gr-iqbalance (optional) - not in pkgsrc

# These are drivers for particular hardware.  They are smallish and
# therefore not optional.  (Also, gr-osmosdr depends on them, so
# avoiding dependencies would not save space.)

#broken
#.include "../../ham/gnuradio-fcd/buildlink3.mk"
.include "../../ham/gnuradio-uhd/buildlink3.mk"
#broken
#.include "../../ham/gr-fcdproplus/buildlink3.mk"
.include "../../ham/rtl-sdr/buildlink3.mk"
.include "../../ham/osmo-sdr/buildlink3.mk"
.include "../../ham/hackrf/buildlink3.mk"

.include "../../ham/gr-osmosdr/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"

# Upstream documents that with qmake, 4.8 is needed, but the cmake
# build requires qt5.  Upstream also outright recommends qt5.
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
