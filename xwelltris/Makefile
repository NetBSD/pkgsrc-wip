# $NetBSD: Makefile,v 1.1.1.1 2008/08/09 12:36:27 leot1990 Exp $
#

DISTNAME=	xwelltris-1.0.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	games
MASTER_SITES=	http://xnc.jinr.ru/xwelltris/src/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://xnc.jinr.ru/xwelltris/
COMMENT=	Tetris like popular game

# TODO: add DESTDIR support
# PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# TODO:
#  Install by default using X11, not SDL. However this need testing, and I
#  need help. :-)
# .include "options.mk"

# XXX: please read the previous TODO comment
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
