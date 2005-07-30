# $NetBSD: Makefile,v 1.13 2005/07/30 13:44:09 dillo Exp $
#

DISTNAME=		ZSNESS_0724
PKGNAME=		zsnes-20050724
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipherswipsite.com/files/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://ipherswipsite.com/zsnes/
COMMENT=		Super NES emulator, development version

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}/zsnes/src
GNU_CONFIGURE=		# defined
USE_TOOLS+=		gmake automake
ONLY_FOR_PLATFORM=	*-*-i386
BUILD_TARGET=		zsnes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
