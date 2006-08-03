# $NetBSD: Makefile,v 1.3 2006/08/03 19:09:14 thomasklausner Exp $
#

PKGNAME=		globulation2-0.8.17
DISTNAME=		glob2-0.8.17
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://lissrv3.epfl.ch/~glob2/data/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://www.globulation2.org/
COMMENT=		Real-Time Strategy (RTS) game providing AI and net mode

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_TOOLS+=             gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
