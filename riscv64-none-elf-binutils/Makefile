# $NetBSD$

DISTNAME=	binutils-2.40
PKGNAME=	cross-riscv64-none-elf-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-riscv64@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal Riscv64 ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

RISCV64ELF_PREFIX=	${PREFIX}/cross-riscv64-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${RISCV64ELF_PREFIX}


CONFIGURE_ARGS+=	--disable-werror --target=riscv64-none-elf
CONFIGURE_ARGS+=	--disable-nls

INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
