# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:40 asau Exp $

DISTNAME=		binutils-2.22
PKGNAME=		avr-binutils-2.22
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no
USE_CROSSBASE=		yes

CONFIGURE_ARGS+=	--disable-werror --target=avr --disable-nls

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	set -e;							\
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

.include "../../mk/bsd.pkg.mk"
