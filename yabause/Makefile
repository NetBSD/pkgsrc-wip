# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 23:58:08 thomasklausner Exp $
#

DISTNAME=		yabause-0.0.6
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://yabause.sourceforge.net/
COMMENT=		Sega Saturn emulator

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/yabause
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yabause

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
