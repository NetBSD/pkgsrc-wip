# $NetBSD: Makefile,v 1.1.1.1 2010/11/26 12:38:21 makoto Exp $

PKG_VERSION=		3.4.6
# PKGNAME will have option name only when explictly selected
PKGNAME=		nios2-gcc-${PKG_VERSION}
#PKGREVISION=		1
CATEGORIES=		cross
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc for Altera FPGA Nios2 processor

EXTRACT_ELEMENTS=	gcc
WRKSRC=			${WRKDIR}/gcc
PATH:=                  ${CROSSBASE}/bin:${PATH}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no

DEPENDS+=		nios2-binutils:../../wip/nios2-binutils

.include		"../../wip/nios2/Makefile.common"

CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}

INFO_FILES=		yes

#.include "../../devel/gmp/buildlink3.mk"  # 4.4 or later
#.include "../../math/mpfr/buildlink3.mk"  # 4.4 or later

# to avoid conflict with binutils (to be fixed by more sophisticated way)
post-install:
	${RM}  ${DESTDIR}${CROSSBASE}/lib/libiberty.a

.include "../../mk/bsd.pkg.mk"
