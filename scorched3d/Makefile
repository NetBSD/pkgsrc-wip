# $NetBSD: Makefile,v 1.4 2010/12/26 05:01:23 davesainty Exp $
#

PKGNAME=	scorched3d-42.1
DISTNAME=	Scorched3D-42.1-src
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/scorched3d/scorched3d/Version%2042.1/
# The following does not work because of space character
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/scorched3d/Version%2042.1/}

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://www.scorched3d.co.uk/
COMMENT=	3D version of the classic DOS game Scorched Earth
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/scorched
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--datadir="${PREFIX}/share/${PKGBASE}"
CONFIGURE_ARGS+=	--with-docdir="${PREFIX}/share/doc/${PKGBASE}"

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
