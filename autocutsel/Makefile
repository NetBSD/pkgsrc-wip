# $NetBSD: Makefile,v 1.1.1.1 2006/05/27 14:35:10 jeremy-c-reed Exp $
#

DISTNAME=		autocutsel-0.8.1
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/autocutsel/ \
			http://www.lepton.fr/tools/autocutsel/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lepton.fr/tools/autocutsel/
COMMENT=		Synchronizes the X11 cutbuffer and CLIPBOARD selection

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/autocutsel

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/autocutsel/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
