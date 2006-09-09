# $NetBSD: Makefile,v 1.8 2006/09/09 02:49:33 obache Exp $
#

DISTNAME=		mppdec-1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.personal.uni-jena.de/~pfk/mpp/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.personal.uni-jena.de/~pfk/mpp/
COMMENT=		Musepack (MPC) audio file decoder

USE_TOOLS+=		gmake

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# do nothing, MAKE_FILE is already set to "Makefile"
# not compiling? see TODO!
.elif ${OPSYS} == "Solaris"
MAKE_FILE=		Makefile.sun
.else
MAKE_FILE=		Makefile.nol
.endif

# see TODO
# .if ${MACHINE_ARCH} == "i386"
# BUILD_DEPENDS+=		nasm>=0.0:../../devel/nasm
# .endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mppdec ${PREFIX}/bin/mppdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mppdec
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${PREFIX}/share/doc/mppdec

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
