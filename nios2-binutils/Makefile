# $NetBSD: Makefile,v 1.3 2011/10/24 15:07:24 makoto Exp $

PKG_VERSION=		2.15
PKGNAME=		nios2-binutils-${PKG_VERSION}
PKG_REVISION=		1
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

EXTRACT_ELEMENTS=	binutils
WRKSRC=			${WRKDIR}/binutils

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
#BUILD_DEFS+=		CROSSBASE	#included in ../nios2/Makefile.common
BUILD_DEFS+=		${NIOS_INFO_DIR}
INFO_FILES=		yes

.include		"../../wip/nios2/Makefile.common"

CONFIGURE_ARGS+=	--disable-nls
# following line is not necessary for binutils-2.18
CONFIGURE_ARGS+=	--disable-werror

# To avoid conflict with other cross/native info files,
NIOS_INFO_DIR=		${PREFIX}/info/${NIOS2_TARGET}
.include "../../mk/bsd.prefs.mk"
INFO_DIR?=		${NIOS_INFO_DIR}

# CONFIGURE_ARGS+=	--infodir=
#  doesn't make it, will be overridden by following variables
#  see mk/configure/gnu-configure.mk
GNU_CONFIGURE_INFODIR=	${NIOS_INFO_DIR}

# following file is reference only, not used at all for the moment
post-install:
	${INSTALL_DATA} files/nios2elf-netbsd.x ${DESTDIR}${CROSSBASE}/${NIOS2_TARGET}/lib/ldscripts

.include "../../mk/bsd.pkg.mk"
