# $NetBSD$

VERSION=	2.5.3

DISTNAME=	gqrx-sdr-src-${VERSION}
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
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-utils/buildlink3.mk"
.include "../../ham/gr-osmosdr/buildlink3.mk"
#.include "../../ham/rtl-sdr/buildlink3.mk"

# Upstream documents >=4.7, but with qt4-libs CMake complains that qt5
# is not found.
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
