# $NetBSD: Makefile,v 1.5 2005/08/11 10:08:23 absd Exp $
#

DISTNAME=		snes9express-1.42
CATEGORIES=		emulators x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snes9express/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://www.linuxgames.com/snes9express/
COMMENT=		Frontend for snes9x written in GTK2

DEPENDS+=		snes9x>=1.39:../../emulators/snes9x

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
