# $NetBSD: Makefile,v 1.2 2005/12/03 17:24:47 bencollver Exp $
#

DISTNAME=		xace-0.4
CATEGORIES=		emulators
MASTER_SITES=		http://hem.passagen.se/tiletech/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}ace.html
COMMENT=		Jupiter Ace emulator

EXTR_PREFIX=		.tar.gz
ONLY_FOR_PLATFORM+=	*-i386
USE_IMAKE=		YES

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	"Configuring to use PREFIX."
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	xmain.c
SUBST_SED.prefix=	-e "s,XXXPREFIXXXX,${PREFIX},g"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xace
	${INSTALL_DATA} ${WRKSRC}/ace.rom ${PREFIX}/share/xace
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xace
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xace
	${INSTALL_DATA} ${WRKSRC}/forth.txt ${PREFIX}/share/doc/xace
	${INSTALL_PROGRAM} ${WRKSRC}/xace ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
