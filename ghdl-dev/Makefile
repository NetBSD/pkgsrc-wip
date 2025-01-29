# $NetBSD$

DISTNAME=	3d758c1cf17ba74a66242412d337e337b8d25af0
PKGNAME=	${GITHUB_PROJECT}-4.1.0-370
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
GITHUB_PROJECT=	ghdl
GITHUB_TAG=	3d758c1cf17ba74a66242412d337e337b8d25af0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghdl/ghdl/
COMMENT=	Open-source simulator/compiler/analyzer for VHDL
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++ # ada
REPLACE_BASH=	scripts/vendors/*.sh


RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-synth
CONFIGURE_ARGS+=	--enable-libghdl


# gcc6-aux dependency is not met on Linux. Besides on Linux mcode backend is preferred, llvm on NetBSD (and possibly others)

PLIST_VARS+=	llvm
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=	GNATMAKE=${PREFIX}/gcc10-aux/bin/gnatmake
CONFIGURE_ARGS+=	--with-llvm-config=${PREFIX}/bin/llvm-config
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/gcc10-aux/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
PLIST.llvm=	yes
.else
# Since we can't build gcc6-aux on Linux, which bootstraps higher gcc versions
CONFIGURE_ENV+=		GNATMAKE=/usr/bin/gnatmake
.endif

.include "../../mk/bsd.pkg.mk"
