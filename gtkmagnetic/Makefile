# $NetBSD: Makefile,v 1.2 2004/04/24 19:27:39 blef Exp $
#

DISTNAME=		Magnetic22Src
PKGNAME=		gtkmagnetic-2.2
WRKSRC=			${WRKDIR}/Gtk
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/magnetic-scrolls/interpreters/magnetic/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/magnetic-scrolls/interpreters/magnetic/
COMMENT=		Interpreter for text adventures from Magnetic Scrolls

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
ALL_TARGET=		gtkmagnetic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkmagnetic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtkmagnetic
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtkmagnetic

.include "../../devel/smpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
