# $NetBSD: Makefile,v 1.3 2004/09/13 15:03:51 cetrox Exp $
#

DISTNAME=		gxmame-0.34b
CATEGORIES=		emulators x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://gxmame.sourceforge.net/
COMMENT=		Frontend for XMame using the GTK library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
