# $NetBSD: Makefile,v 1.1.1.1 2012/02/07 03:01:20 makoto Exp $

DISTNAME=		avr-libc-1.7.1
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen>=1.6.3nb1:../../devel/doxygen
BUILD_DEPENDS+=		transfig-[0-9]*:../../print/transfig
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST= no
USE_CROSSBASE=		yes

CONFIGURE_ENV+=		AS=${PREFIX}/bin/avr-as
CONFIGURE_ENV+=		AR=${PREFIX}/bin/avr-ar
CONFIGURE_ENV+=		RANLIB=${PREFIX}/bin/avr-ranlib
CONFIGURE_ENV+=		CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q} --host=avr
CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc

# Adding ${LOCALBASE}/cross/bin at installation time.
#   In doc/examples/demo directory, we have sample Makefile both for
#   generating *.hex file at pkg installation time, and for installing
#   Makefile itself.  That Makefile should be for general purpose, meaning
#     OBJCOPY = avr-objcopy
#   line should be intact. While pkg installation time it should refer
#   wrapper ${LOCALBASE}/cross/bin files. See patch-doc_Makefile.in adding
#   related one line.

SUBST_CLASSES+=		demo
SUBST_STAGE.demo=	pre-configure
SUBST_MESSAGE.demo=	Add cross/bin on PATH for OBJCOPY (avr-objcopy) etc
SUBST_FILES.demo=	doc/Makefile.in
SUBST_SED.demo=		-e 's|@@@PATH@@@|${PREFIX}/bin:${PATH:Q}|g'

# work around for buildlink wrapper does not take care ${LOCALBASE}/cross dir
# necessary only when USE_CROSSBASE = yes
pre-build:
	(set -e ; cd ${BUILDLINK_DIR};	\
	${MKDIR} -p cross/bin;	\
	${LN} -fs ${PREFIX}/bin/* cross/bin)

post-build:
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE}
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE} dox

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/avr-libc
	set -e;	\
	for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${DESTDIR}${PREFIX}/share/doc/avr-libc/examples/demo; \
	done

.include "../../wip/avr-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX: very evil hack to override CC, doing it via CONFIGURE_ENV doesn't work.
ALL_ENV+= CC=${PREFIX}/bin/avr-gcc
