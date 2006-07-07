# $NetBSD: Makefile,v 1.19 2006/07/07 11:04:05 dillo Exp $
#

DISTNAME=		ZSNESS_0319
PKGNAME=		zsnes-20060319
CATEGORIES=		emulators
MASTER_SITES=		http://files.ipherswipsite.com/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://zsnes.ipherswipsite.com/
COMMENT=		Super NES emulator, development version

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}/src
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake automake
USE_LANGUAGES+=		c++
ONLY_FOR_PLATFORM=	*-*-i386
BUILD_TARGET=		zsnes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
