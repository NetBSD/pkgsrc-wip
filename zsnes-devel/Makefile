# $NetBSD: Makefile,v 1.4 2004/08/04 10:29:53 dillo Exp $
#

DISTNAME=		ZSNESS_0803
PKGNAME=		zsnes-20040803
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipherswipsite.com/files/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://ipherswipsite.com/zsnes/
COMMENT=		Super NES emulator, development version

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}/zsnes/src
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+=		make
ONLY_FOR_PLATFORM=	*-*-i386
ALL_TARGET=		zsnes
USE_X11=		# defined

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/automake.mk"

pre-configure:
	cd ${WRKSRC}; \
	${ACLOCAL}; \
	${AUTOCONF}

.include "../../mk/bsd.pkg.mk"
