# $NetBSD: Makefile,v 1.1.1.1 2003/09/24 12:50:32 cubidou Exp $
#

DISTNAME=		monkey-bubble-0.1
CATEGORIES=		games
MASTER_SITES=		http://monkey-bubble.tuxfamily.org/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://monkey-bubble.tuxfamily.org/
COMMENT=		Bust'a'move clone written in C for GNOME2

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../misc/gstreamer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
