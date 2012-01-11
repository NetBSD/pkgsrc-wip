# $NetBSD: Makefile,v 1.4 2012/01/11 19:54:00 thomasklausner Exp $
#

DISTNAME=		autocutsel-0.9.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/autocutsel/ \
			http://www.lepton.fr/tools/autocutsel/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lepton.fr/tools/autocutsel/
COMMENT=		Synchronizes the X11 cutbuffer and CLIPBOARD selection
LICENSE=		gnu-gpl-v2

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
