# $NetBSD: Makefile,v 1.1.1.1 2010/05/01 19:49:25 thomasklausner Exp $
#

DISTNAME=	smw-1.8-beta2-src
PKGNAME=	smw-1.8beta2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://smw.supersanctuary.net/18Beta2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://72dpiarmy.supersanctuary.net/viewforum.php?f=1
COMMENT=	Super Mario War - stomp the Marios
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
