# $NetBSD: Makefile,v 1.10 2012/09/29 00:50:35 asau Exp $
#

PKGNAME=		globulation2-0.8.21
DISTNAME=		glob2-0.8.21
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://globulation2.org/releases/0.8.21/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://globulation2.org/wiki/
COMMENT=		Real-Time Strategy (RTS) game providing AI and net mode

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
