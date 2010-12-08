# $NetBSD: Makefile,v 1.11 2010/12/08 23:10:20 asau Exp $
#

DISTNAME=	llvm-2.8
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown
USE_LANGUAGES+=	c c++
MAKE_DIRS+=	etc/llvm

CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!

INSTALLATION_DIRS=	bin lib

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only

#CONF_FILES=	share/examples/llvm/c etc/llvm/c
#CONF_FILES+=	share/examples/llvm/c++ etc/llvm/c++
#CONF_FILES+=	share/examples/llvm/cpp etc/llvm/cpp
#CONF_FILES+=	share/examples/llvm/cxx etc/llvm/cxx
#CONF_FILES+=	share/examples/llvm/ll etc/llvm/ll
#CONF_FILES+=	share/examples/llvm/st etc/llvm/st

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

#.include "../../lang/ocaml/buildlink3.mk"
TEST_TARGET=	check unittests

# Get it from Subversion repository:
SVN_REPOSITORIES=	llvm
SVN_ROOT.llvm=		http://llvm.org/svn/llvm-project/llvm/trunk
SVN_MODULE.llvm=	llvm

#AKE_FLAGS+=		prefix=${DESTDIR:Q}${PREFIX}

PKGNAME=		llvm-2.8.99
WRKSRC=			${WRKDIR}/${SVN_MODULE.llvm}

CHECK_PORTABILITY_SKIP= utils/buildit/.svn/text-base/build_llvm.svn-base \
			utils/buildit/build_llvm

.include "../../mk/bsd.prefs.mk"

SO_SUFFIX=		so
PLIST_SUBST+=   	SO_SUFFIX=${SO_SUFFIX}
PRINT_PLIST_AWK+=	{gsub(/\.${SO_SUFFIX}$$/, ".$${SO_SUFFIX}");}

.if ${OPSYS} == "Darwin"
SO_SUFFIX=		dylib
.endif
    ## warning: ....usr/pkg/lib/libCompilerDriver.a: executable bit is set on non-executable file.
#post-install:
#	${CHMOD}	-x ${DESTDIR}${PREFIX}/lib/lib*.a

.include "../../wip/mk/svn-package.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
