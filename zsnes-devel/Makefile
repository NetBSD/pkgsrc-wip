# $NetBSD: Makefile,v 1.1.1.1 2004/06/17 23:03:31 dillo Exp $
#

DISTNAME=		ZSNESS_0609
PKGNAME=		zsnes-20040609
CATEGORIES=		emulators
MASTER_SITES=		http://ipher.emuhost.com/files/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.zsnes.com/sourceforge.php
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

post-extract:
	${MKDIR} ${WRKDIR}/zsnes
	for n in ${WRKDIR}/zsnes\\*; \
	do \
		${MV} $$n `${ECHO} $$n | ${SED} 's!\\\\!/!'`; \
	done

pre-configure:
	cd ${WRKSRC}; \
	${ACLOCAL}; \
	${AUTOCONF}

.include "../../mk/bsd.pkg.mk"
