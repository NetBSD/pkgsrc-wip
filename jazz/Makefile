# $NetBSD: Makefile,v 1.2 2003/06/02 19:14:42 bencollver Exp $
#

DISTNAME=		jazz-src-4.1.3
PKGNAME=		jazz-4.1.3
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.jazzware.com/pub/jazz/stable/source/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.jazzware.com
COMMENT=		MIDI sequencer

BUILD_DEPENDS+=		tex2rtf-*:../../converters/tex2rtf

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
CFLAGS+=		-fpermissive

pre-build:
	cd ${WRKSRC}/bitmaps && ${GMAKE}
	cd ${WRKSRC}/src && ${GMAKE} CXXFLAGS="${CXXFLAGS}" motif/depend
	cd ${WRKSRC}/doc && ${GMAKE} xlp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/motif/jazz ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/jazz
	${INSTALL_DATA} ${WRKSRC}/doc/jazz.xlp \
		${WRKSRC}/jazz.cfg \
		${WRKSRC}/conf/*jzi \
		${PREFIX}/share/jazz

.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/wx1Motif/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"
.include "../../mk/x11.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
