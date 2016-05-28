# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:08 asau Exp $
#

DISTNAME=		xdiskusage-1.48
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://xdiskusage.sourceforge.net/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://xdiskusage.sourceforge.net/
COMMENT=		Graphical space disk viewer


USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
