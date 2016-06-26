# $NetBSD$

VERSION=	2.5.3

DISTNAME=	gqrx-sdr-src-${VERSION}
CATEGORIES=	wip
MASTER_SITES=	https://github.com/csete/gqrx/releases/download/v${VERSION}/
EXTRACT_SUFX=	.tar.xz
PKGNAME=	gqrx

MAINTAINER=	gdt@netbsd.org
HOMEPAGE=	http://gqrx.dk/
COMMENT=	SDR GUI using GNU Radio
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/gqrx-sdr-${VERSION}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-utils/buildlink3.mk"
# does not exist yet
#.include "../../ham/gnuradio-osmosdr/buildlink3.mk"

.include "../../ham/rtl-sdr/buildlink3.mk"

# Upstream documents >=4.7, but with qt4-libs CMake complains that qt5
# is not found.
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
