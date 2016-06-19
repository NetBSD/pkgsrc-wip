# $NetBSD: Makefile,v 1.1 2013/11/17 01:03:27 makoto Exp $
.include		"../../cross/nios2/Makefile.common"
PKGNAME=		nios2-gdb-${PKG_VERSION}
PKG_VERSION=		7.6.1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU Debugger (gdb) for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v3

#USE_TOOLS+=		ksh gettext gmake makeinfo perl tar automake autoconf gawk
USE_TOOLS+=		tar makeinfo
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_GNU_CONFIGURE_HOST=	no
WRKSRC=			${WRKDIR}/gdb-nios2

CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}

PLIST_VARS+=		doc
TEST_TARGET=		check

do-extract:
	(cd ${WRKDIR}; tar zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}	\
	        sourceryg++-2013.05-43-nios2-linux-gnu/gdb-2013.05-43.tar.bz2;\
	tar zxf sourceryg++-2013.05-43-nios2-linux-gnu/gdb-2013.05-43.tar.bz2;\
	)

# to avoid conflict with binutils (to be fixed by more sophisticated way)
post-install:
	${RM}  ${DESTDIR}${PREFIX}/cross/lib/libiberty.a

.include "../../mk/bsd.pkg.mk"
