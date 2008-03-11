# $NetBSD: Makefile,v 1.2 2008/03/11 00:17:37 tnn2 Exp $
#

DISTNAME=		autocutsel-0.9.0
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/autocutsel/ \
			http://www.lepton.fr/tools/autocutsel/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lepton.fr/tools/autocutsel/
COMMENT=		Synchronizes the X11 cutbuffer and CLIPBOARD selection

PKG_DESTDIR_SUPPORT=	user-destdir

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
