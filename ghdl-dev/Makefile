# $NetBSD$

GITHUB_PROJECT=	ghdl
GITHUB_TAG=	f1de234f5e77eb8fb765da945a0bf34ec4abb864
DISTNAME=	f1de234f5e77eb8fb765da945a0bf34ec4abb864
PKGNAME=	${GITHUB_PROJECT}-dev-5.0.0.9655
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
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
TOOL_DEPENDS+=	gcc10-aux-[0-9]*:../../lang/gcc10-aux
CONFIGURE_ENV+=		GNATMAKE=${PREFIX}/gcc10-aux/bin/gnatmake
CONFIGURE_ARGS+=	--with-llvm-config=${PREFIX}/bin/llvm-config
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
PLIST.llvm=	yes
.else
# Since we can't build gcc6-aux on Linux, which bootstraps higher gcc versions
CONFIGURE_ENV+=		GNATMAKE=/usr/bin/gnatmake
.endif

.include "../../mk/bsd.pkg.mk"
