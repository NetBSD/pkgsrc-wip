# $NetBSD: Makefile,v 1.4 2005/07/21 16:34:07 thomasklausner Exp $
#

DISTNAME=		snes9express-1.42
CATEGORIES=		emulators x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snes9express/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://www.linuxgames.com/snes9express/
COMMENT=		Frontend for snes9x written in GTK2

DEPENDS+=		snes9x>=1.39:../../emulators/snes9x

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
