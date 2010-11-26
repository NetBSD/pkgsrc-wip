# $NetBSD: Makefile,v 1.1.1.1 2010/11/26 12:38:21 makoto Exp $

PKG_VERSION=		2.15
PKGNAME=		nios2-binutils-${PKG_VERSION}
#PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/
#EXTRACT_SUFX=		.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for Altera FPGA Nios2 processor

EXTRACT_ELEMENTS=	binutils
WRKSRC=			${WRKDIR}/binutils

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
#BUILD_DEFS+=		CROSSBASE	#included in ../nios2/Makefile.common
INFO_FILES=		yes

.include		"../../wip/nios2/Makefile.common"

CONFIGURE_ARGS+=	--disable-nls
# following line is not necessary for binutils-2.18
CONFIGURE_ARGS+=	--disable-werror

# following file is reference only, not used at all for the moment
post-install:
	${INSTALL_DATA} files/nios2elf-netbsd.x ${DESTDIR}${CROSSBASE}/${NIOS2_TARGET}/lib/ldscripts

.include "../../mk/bsd.pkg.mk"
