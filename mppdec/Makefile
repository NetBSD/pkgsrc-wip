# $NetBSD: Makefile,v 1.2 2004/04/19 16:06:38 thomasklausner Exp $
#

DISTNAME=		mppdec-1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.personal.uni-jena.de/~pfk/mpp/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.personal.uni-jena.de/~pfk/mpp/
COMMENT=		Musepack (MPC) audio file decoder

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# do nothing, MAKEFILE is already set to "Makefile"
# not compiling? see TODO!
.elif ${OPSYS} == "Solaris"
MAKEFILE=		Makefile.sun
.else
MAKEFILE=		Makefile.nol
.endif

# see TODO
# .if ${MACHINE_ARCH} == "i386"
# BUILD_DEPENDS+=		nasm>=0.0:../../devel/nasm
# .endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mppdec ${PREFIX}/bin/mppdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mppdec
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${PREFIX}/share/doc/mppdec

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
