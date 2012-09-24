# $NetBSD: Makefile,v 1.6 2012/09/24 16:56:40 asau Exp $
#

DISTNAME=		autocutsel-0.9.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/autocutsel/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.nongnu.org/autocutsel/
COMMENT=		Synchronizes the X11 cutbuffer and CLIPBOARD selection
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/autocutsel

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	  ${DESTDIR}${PREFIX}/share/doc/autocutsel/

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
