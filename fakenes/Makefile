# $NetBSD: Makefile,v 1.9 2005/05/24 10:29:39 rillig Exp $
#

DISTNAME=		fakenes-0.3.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fakenes/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://fakenes.sourceforge.net/
COMMENT=		Portable Open Source NES emulator

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

# disable netplay support: needs nl.h
CONFIGURE_ARGS+=	--without-hawknl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fakenes ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fakenes
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/fakenes
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fakenes

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
