# $NetBSD$

DISTNAME=	xoscope-2.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xoscope/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://xoscope.sourceforge.net/
COMMENT=	Sound card oscilloscope
LICENSE=	gnu-gpl-v2

DEPENDS+=	alsa-plugins-oss-[0-9]*:../../audio/alsa-plugins-oss

USE_TOOLS+=	pkg-config gmake perl

GNU_CONFIGURE=	yes

EGDIR=		share/examples/xoscope

INSTALLATION_DIRS+=	bin man/man1 ${EGDIR}
INSTALLATION_DIRS+=	share/applications share/metainfo share/pixmaps

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtkdatabox/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
