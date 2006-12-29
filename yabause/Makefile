# $NetBSD: Makefile,v 1.6 2006/12/29 00:43:49 thomasklausner Exp $

DISTNAME=	yabause-0.8.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
USE_DIRS+=	xdg-1.4
WRKSRC=	${WRKDIR}/${PKGBASE}

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
