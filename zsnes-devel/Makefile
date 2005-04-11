# $NetBSD: Makefile,v 1.7 2005/04/11 21:16:38 tvierling Exp $
#

DISTNAME=		ZSNESS_0920
PKGNAME=		zsnes-20040920
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipherswipsite.com/files/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://ipherswipsite.com/zsnes/
COMMENT=		Super NES emulator, development version

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}/zsnes/src
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+=		make
ONLY_FOR_PLATFORM=	*-*-i386
BUILD_TARGET=		zsnes
USE_X11=		# defined

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/automake.mk"

pre-configure:
	cd ${WRKSRC}; \
	${ACLOCAL}; \
	${AUTOCONF}

.include "../../mk/bsd.pkg.mk"
