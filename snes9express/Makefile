# $NetBSD: Makefile,v 1.1.1.1 2004/09/13 13:17:48 cetrox Exp $
#

DISTNAME=		snes9express-1.42
CATEGORIES=		emulators x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snes9express/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://www.linuxgames.com/snes9express/
COMMENT=		Frontend for snes9x written in GTK2

DEPENDS+=		snes9x>=1.39:../../emulators/snes9x

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../mk/autoconf.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
