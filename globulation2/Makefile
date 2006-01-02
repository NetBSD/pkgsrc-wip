# $NetBSD: Makefile,v 1.1 2006/01/02 21:27:14 h2m Exp $
#

PKGNAME=		globulation2-0.8.17
DISTNAME=		glob2-0.8.17
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://lissrv3.epfl.ch/~glob2/data/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://www.globulation2.org/
COMMENT=		Real-Time Strategy (RTS) game providing AI and net mode

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=        --prefix=${PREFIX:Q}

USE_TOOLS+=             gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"

.include "../../audio/speex/buildlink3.mk"

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
