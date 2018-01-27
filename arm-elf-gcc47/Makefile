# $NetBSD: Makefile,v 1.1 2015/10/11 01:14:56 ryoon Exp $

DISTNAME=		gcc-4.7.4
PKGNAME=		cross-arm-elf-${DISTNAME}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-4.9.3/}
NEWLIBVER=		2.2.0
SITES.newlib-${NEWLIBVER}.tar.gz= ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			newlib-${NEWLIBVER}.tar.gz

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal classic ARM ELF
EXTRACT_SUFX=		.tar.bz2

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo= yes

DEPENDS+=	cross-arm-elf-binutils-[0-9]*:../../wip/arm-elf-binutils

USE_LANGUAGES+=		c c++

ARMELF_PREFIX=		${PREFIX}/cross-arm-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

HOSTDIR=		build-${MACHINE_ARCH}--${LOWER_OPSYS}

CONFIGURE_ARGS+=	--target=arm-elf
CONFIGURE_ARGS+=	--enable-obsolete
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

INSTALLATION_DIRS+=	bin

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
