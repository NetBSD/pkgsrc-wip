# $NetBSD: Makefile,v 1.1.1.1 2003/08/24 23:53:50 poppnk Exp $
#

DISTNAME=	dgen-sdl-1.22
CATEGORIES=	emulators
MASTER_SITES=	http://www.pknet.com/~joe/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.pknet.com/~joe/dgen-sdl.html
COMMENT=	Genesis/Megadrive emulator for Unix platforms

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes
USE_BUILDLINK2=	yes

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
