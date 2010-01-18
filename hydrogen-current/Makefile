# $NetBSD: Makefile,v 1.7 2010/01/18 09:38:25 thomasklausner Exp $

DISTNAME=	hydrogen-0.9.3
PKGNAME=	${DISTNAME:S/-/-current-/}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer

CONFLICTS+=	hydrogen-[0-9]* libhydrogen-[0-9]*
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pax
GNU_CONFIGURE=	yes
LDFLAGS+=	-lossaudio

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-jack-support

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native" || exists(${X11BASE}/include/X11/extensions/Xinerama.h)
.include "../../x11/libXinerama/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xinerama
.endif

BUILDLINK_DEPMETHOD.libXt?=	build
DEPENDS+=	liblrdf>0:../../textproc/liblrdf

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} hydrogen hydrogenPlayer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/hydrogen/data
	cd ${WRKSRC}/data && pax -rwpp . ${PREFIX}/share/hydrogen/data
	${INSTALL_LIB_DIR} ${PREFIX}/lib/hydrogen/plugins
	cd ${WRKSRC}/plugins/wasp && ${INSTALL_LIB} *.so ${PREFIX}/lib/hydrogen/plugins
	${INSTALL_MAN} ${WRKSRC}/data/doc/man/C/hydrogen.1 ${PREFIX}/${PKGMANDIR}/man1

#.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
