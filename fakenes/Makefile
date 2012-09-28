# $NetBSD: Makefile,v 1.14 2012/09/28 22:10:13 asau Exp $
#

DISTNAME=		fakenes-0.5.4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fakenes/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fakenes.sourceforge.net/
COMMENT=		Portable Open Source NES emulator

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

# disable netplay support: needs nl.h
CONFIGURE_ARGS+=	--without-hawknl
# no openal support
CONFIGURE_ARGS+=	--without-openal

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakenes ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fakenes
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/fakenes
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fakenes

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
