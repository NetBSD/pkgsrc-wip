# $NetBSD: Makefile,v 1.12 2016/03/05 11:28:35 jperkin Exp $
#
VERSION=	0.9.2
DISTNAME=	supertuxkart-${VERSION}-src
PKGNAME=	${DISTNAME:S/-src//}
#PKGREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=supertuxkart/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supertuxkart.sourceforge.net/
COMMENT=	Free 3D kart racing game
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/supertuxkart-${VERSION}
USE_CMAKE=		yes
#USE_LIBTOOL=		yes
#USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake

CXXFLAGS+=	-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_

CMAKE_ARGS+=	-DUSE_WIIUSE=0 \
		-DUSE_FRIBIDI=0

#.include "../../devel/SDL/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
