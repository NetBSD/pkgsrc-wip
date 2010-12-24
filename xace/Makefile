# $NetBSD: Makefile,v 1.7 2010/12/24 18:34:49 noud4 Exp $
#

DISTNAME=		xace-0.4
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://hem.passagen.se/tiletech/

MAINTAINER=		pkgsrc-users@NetBSD.org
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

.if ${X11_TYPE} == "modular"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
