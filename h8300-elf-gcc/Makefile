# $NetBSD: Makefile,v 1.1 2014/08/09 15:24:28 makoto Exp $

DISTNAME=		gcc-4.8.3
PKGNAME=		${DISTNAME:C/^/cross-h8300-elf-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/releases/${DISTNAME}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		#empty
COMMENT=		GCC compiler for h8300-elf
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=		cross-h8300-elf-binutils-[0-9]*:../../cross/h8300-elf-binutils

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no
INFO_FILES=		yes

CONFIGURE_ARGS+=	--target=${CROSS_TARGET}
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
#CONFIGURE_ARGS+=	--with-newlib
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
CROSS_TARGET=		h8300-elf

pre-configure:
	${MKDIR} ${WRKDIR}/obj
	${LN} -s ${WRKDIR}/obj/gcc/include/unwind.h ${WRKSRC}/gcc/unwind.h

# To avoid the conflict with other cross and native compiler
post-install:
	(cd ${DESTDIR}${PREFIX}/lib; \
	 ${MV} libiberty.a gcc/${CROSS_TARGET}/ )
	# pkg_add: Conflicting PLIST with avr-gcc-4.8.3: man/man7/fsf-funding.7
	(cd ${DESTDIR}${PREFIX}/${PKGMANDIR}; \
	${RM}  man7/fsf-funding.7;\
	${RM}  man7/gfdl.7;\
	${RM}  man7/gpl.7)

CONFIGURE_DIRS=		${WRKDIR}/obj
CONFIGURE_SCRIPT=	${WRKSRC}/configure

INSTALLATION_DIRS+=	h8300-elf/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
# mpc is required since gcc-4.5.x
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
