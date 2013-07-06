# $NetBSD: Makefile,v 1.7 2013/07/06 15:07:48 makoto Exp $

DISTNAME=		binutils-2.23.2
PKGNAME=		${DISTNAME:S/^/avr-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--disable-werror --target=avr --disable-nls

AUTO_MKDIRS=		yes

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	set -e;							\
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

# emulator/simulavr wants libbfd.so or libbfd.a and bfd.h
#  --with-bfd=path  location of AVR-binutils version of libbfd install
#  where include/bfd.h and lib/libbfd.a are found (from binutils)
post-build:
	set -e;							\
	(cd ${WRKSRC}/bfd; ${GMAKE} all libbfd.a);

post-install:
	(cd ${WRKSRC}/bfd; 					\
	${GMAKE} install-exec install-data; 			\
	${LIBTOOL} --mode install ${INSTALL_DATA} libbfd.la ${DESTDIR}${PREFIX}/avr/lib;	\
	${INSTALL_DATA} bfd.h ${DESTDIR}${PREFIX}/avr/include;	\
	)
	(cd ${WRKSRC}/libiberty;				\
	${MV} ${DESTDIR}${PREFIX}/lib/libiberty.a		\
	      ${DESTDIR}${PREFIX}/avr/lib/libiberty.a		\
	)
.include "../../mk/bsd.pkg.mk"
