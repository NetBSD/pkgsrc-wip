# $NetBSD: Makefile,v 1.1.1.1 2003/07/01 07:48:03 blef Exp $

DISTNAME=		VisualBoyAdvance-1.5.1-src
PKGNAME=		vba-1.5.1
WRKSRC=			${WRKDIR}/VisualBoyAdvance-1.5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vba/}
EXTRACT_SUFX=		.zip

MAINTAINER=		soren@blef.org
HOMEPAGE=		http://vboy.emuhq.com/
COMMENT=		gameboy advance emulator

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-c-core
CONFIGURE_ARGS+=	--without-mmx

USE_GCC3=		# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/TestEmu ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/VisualBoyAdvance ${PREFIX}/bin

.include "../../mk/gcc.buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
