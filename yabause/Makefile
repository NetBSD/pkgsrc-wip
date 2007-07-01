# $NetBSD: Makefile,v 1.7 2007/07/01 13:59:50 obache Exp $

DISTNAME=	yabause-0.8.5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
USE_DIRS+=	xdg-1.4

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
