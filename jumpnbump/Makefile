# $NetBSD: Makefile,v 1.1.1.1 2005/03/31 18:13:49 airhead Exp $
#

DISTNAME=		jumpnbump-1.50
CATEGORIES=		wip games
MASTER_SITES=		http://jumpbump.mine.nu/port/

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://jumpbump.mine.nu/
COMMENT=		Game with cute rabbits and lots of blood

USE_BUILDLINK3=		yes
MAKE_ENV+=		SDL_PREFIX="${BUILDLINK_PREFIX.SDL}"
MAKE_ENV+=		SDL_mixer_PREFIX="${BUILDLINK_PREFIX.SDL_mixer}"
MAKE_ENV+=		SDL_net_PREFIX="${BUILDLINK_PREFIX.SDL_net}"

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
