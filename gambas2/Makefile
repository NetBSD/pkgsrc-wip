# $NetBSD: Makefile,v 1.5 2010/01/18 09:38:21 thomasklausner Exp $
#

DISTNAME=		gambas2-1.9.40
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gambas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://gambas.sourceforge.net/
COMMENT=		IDE similar to Visual Basic

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
