# $NetBSD: Makefile,v 1.5 2006/01/17 10:20:47 rillig Exp $
#

DISTNAME=		xace-0.4
CATEGORIES=		emulators
MASTER_SITES=		http://hem.passagen.se/tiletech/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}ace.html
COMMENT=		Jupiter Ace emulator

EXTR_PREFIX=		.tar.gz
USE_IMAKE=		YES

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Configuring to use PREFIX.
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	xmain.c
SUBST_SED.prefix=	-e "s,XXXPREFIXXXX,${PREFIX},g"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "hpcmips"
SUBST_CLASSES+=		scale
SUBST_MESSAGE.prefix=	Fixing scale.
SUBST_STAGE.scale=	post-patch
SUBST_FILES.scale=	Imakefile
SUBST_SED.scale=	-e 's,SCALE=2,SCALE=1,'
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xace
	${INSTALL_DATA} ${WRKSRC}/ace.rom ${PREFIX}/share/xace
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xace
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xace
	${INSTALL_DATA} ${WRKSRC}/forth.txt ${PREFIX}/share/doc/xace
	${INSTALL_PROGRAM} ${WRKSRC}/xace ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
