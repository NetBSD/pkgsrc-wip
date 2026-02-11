# $NetBSD$

DISTNAME=		avr-libc-2.3.1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=avrdudes/}
GITHUB_PROJECT=		avr-libc
GITHUB_RELEASE=		${DISTNAME:S/./_/g}-release
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://avrdudes.github.io/avr-libc/
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers
LICENSE=		modified-bsd

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=avr
CONFIGURE_ARGS+=	--disable-versioned-doc
CONFIGURE_ARGS+=	CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/avr/include"

# In share/doc/avr-libc/examples/demo directory, we have sample Makefile both
# for generating *.hex file at pkg installation time, and for installing
# Makefile itself. That Makefile should be for general purpose, meaning
#
#     OBJCOPY = avr-objcopy
#
# line should be intact. While pkg installation time it should refer
# wrapper ${LOCALBASE}/cross/bin files. See patch-doc_Makefile.in adding
# related one line.
SUBST_CLASSES+=		demo
SUBST_STAGE.demo=	pre-configure
SUBST_MESSAGE.demo=	Add cross/bin on PATH for OBJCOPY (avr-objcopy) etc
SUBST_FILES.demo=	doc/Makefile.in
SUBST_SED.demo=		-e 's|@@@PATH@@@|${PREFIX}/bin:${PATH:Q}|g'

.include "options.mk"

.include "../../wip/avr-binutils/buildlink3.mk"
.include "../../wip/avr-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Not to be overridden as --mandir=${PREFIX}, put the line here.
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/doc/avr-libc/man
