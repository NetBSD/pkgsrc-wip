# $NetBSD: Makefile,v 1.3 2012/10/03 18:15:32 asau Exp $

PKG_VERSION=		3.4.6
# PKGNAME will have option name only when explictly selected
PKGNAME=		nios2-gcc-${PKG_VERSION}
#PKGREVISION=		1
CATEGORIES=		cross
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

EXTRACT_ELEMENTS=	gcc
WRKSRC=			${WRKDIR}/gcc
PATH:=                  ${CROSSBASE}/bin:${PATH}

USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no
#BUILD_DEFS+=		CROSSBASE	#included in ../nios2/Makefile.common

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
