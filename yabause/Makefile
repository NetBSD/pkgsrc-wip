# $NetBSD: Makefile,v 1.5 2006/12/28 09:26:41 wilouf Exp $

DISTNAME=	yabause-0.8.0
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
WRKSRC=	${WRKDIR}/${PKGBASE}

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
