# $NetBSD: common.mk,v 1.1.1.1 2010/08/11 14:33:10 tnn2 Exp $
#

DISTNAME=	gcc-4.5.1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		mingw-w64-binutils-[0-9]*:../../wip/mingw-w64-binutils
DEPENDS+=		mingw-w64-headers-[0-9]*:../../wip/mingw-w64-headers

DISTINFO_FILE=		${.CURDIR}/../mingw-w64-gcc/distinfo
PATCHDIR=		${.CURDIR}/../mingw-w64-gcc/patches

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CROSSBASE=		yes
USE_TOOLS+=		gmake flex bison makeinfo perl
INFO_FILES=		yes

# XXX fixme: shared build is borked with sjlj
CONFIGURE_ARGS+=	--enable-sjlj-exceptions		\
			--disable-shared			\
			--enable-version-specific-runtime-libs	\
			--enable-fully-dynamic-string		\
			--disable-libssp			\
			--with-system-zlib			\
			--enable-languages=c,c++		\
			--target=x86_64-w64-mingw32		\
			--enable-targets=all

CONFIGURE_DIRS=         ../build
BUILD_DIRS=             ../build
INSTALL_DIRS=           ../build

CONFIGURE_ENV+=		CFLAGS_FOR_TARGET="-g -O2"
CONFIGURE_ENV+=		CXXFLAGS_FOR_TARGET="-g -O2"

CONFIGURE_SCRIPT=	${WRKSRC}/configure

post-extract:
	mkdir ${WRKDIR}/build

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
