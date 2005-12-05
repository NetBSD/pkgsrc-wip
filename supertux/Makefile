# $NetBSD: Makefile,v 1.3 2005/12/05 22:27:48 rillig Exp $
#

DISTNAME=		supertux-0.1.3
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://download.berlios.de/supertux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://supertux.berlios.de/
COMMENT=		2D jump'n run game in the style of the Super Mario ones

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=		gmake

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
