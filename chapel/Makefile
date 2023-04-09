# $NetBSD$

DISTNAME=	chapel-1.30.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=chapel-lang/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	jhigh@NetBSD.org
HOMEPAGE=	https://chapel-lang.org/
COMMENT=	The Chapel programming language
LICENSE=	apache-2.0

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

USE_TOOLS=		bash:run pkg-config gmake perl
USE_LIBTOOL=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=/usr/pkg
CONFIGURE_ENV+=		CHPL_HOST_COMPILER=gnu
CONFIG_SHELL=		bash

TEST_TARGET=		check

# TODO: detect clang and set to 'clang' instead
MAKE_ENV+=		CHPL_HOST_COMPILER=gnu
# llvm 15 not supported yet as of 1.29.0
MAKE_ENV+=		CHPL_LLVM=none

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/chapel/1.30/compiler

USE_LANGUAGES=	c c++ fortran

PLIST_SUBST+=		VERSION=${PKGVERSION_NOREV:R}

PKGCONFIG_OVERRIDE+=	third-party/hwloc/hwloc-src/hwloc.pc.in
PKGCONFIG_OVERRIDE+=	third-party/jemalloc/jemalloc-src/jemalloc.pc.in

REPLACE_BASH+=		configure
REPLACE_BASH+=		modules/internal/fixInternalDocs.sh
REPLACE_BASH+=		util/config/*.bash

REPLACE_SH+=		third-party/qthread/qthread-src/configure
REPLACE_SH+=		util/config/compileline
REPLACE_SH+=		util/config/llvmVersions
REPLACE_SH+=		util/printchplenv

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PERL+=		modules/dists/fixDistDocs.perl

REPLACE_PYTHON+=	util/chplenv/*.py
REPLACE_PYTHON+=	util/chplenv/third-party-pkgs
REPLACE_PYTHON+=	util/config/*.py
REPLACE_PYTHON+=	util/config/generate-copyright
REPLACE_PYTHON+=	util/config/generate-license
REPLACE_PYTHON+=	util/config/generate-reservedSymbolNames
REPLACE_PYTHON+=	util/config/update-if-different
REPLACE_PYTHON+=	util/config/write-git-sha
REPLACE_PYTHON+=	util/printchplenv

SUBST_CLASSES+=			penvperl
SUBST_STAGE.penvperl=		pre-install
SUBST_FILES.penvperl=		third-party/jemalloc/install/*/*/bin/jeprof
SUBST_SED.penvperl=		-e "s,/usr/bin/env perl,${PERL5},g"

CHECK_PORTABILITY_SKIP+=	third-party/libunwind/libunwind-src/configure
CHECK_PORTABILITY_SKIP+=	third-party/libunwind/libunwind-src/tests/check-namespace.sh.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
