# $NetBSD: Makefile,v 1.5 2005/05/24 10:31:47 rillig Exp $
#

DISTNAME=		uqm-0.3-source
PKGNAME=		uqm-0.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sc2/}
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		uqm-0.3-content.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://sc2.sourceforge.net/
COMMENT=		Star Control 2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11=		YES
USE_TOOLS=		gmake
WRKSRC=			${WRKDIR}/${PKGNAME}
DIST_SUBDIR=		uqm
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

do-configure:
	cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} LIBOSSAUDIO=${LIBOSSAUDIO} \
		./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/uqm-0.3-content.zip \
		${PREFIX}/share/uqm/content/packages
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uqm
	${INSTALL_DATA} ${WRKSRC}/doc/users/manual.txt ${PREFIX}/share/doc/uqm

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
