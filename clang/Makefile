# $NetBSD: Makefile,v 1.7 2011/07/09 17:38:45 asau Exp $
#

DISTNAME=	llvm-2.6
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake perl:build chown
GNU_CONFIGURE=	yes
MAKE_DIRS+=	etc/llvm
CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!
# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only
CONFIGURE_ARGS+= --disable-optimized

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin lib libexec


#CONF_FILES=	share/examples/llvm/c etc/llvm/c
#CONF_FILES+=	share/examples/llvm/c++ etc/llvm/c++
#CONF_FILES+=	share/examples/llvm/cpp etc/llvm/cpp
#CONF_FILES+=	share/examples/llvm/cxx etc/llvm/cxx
#CONF_FILES+=	share/examples/llvm/ll etc/llvm/ll
#CONF_FILES+=	share/examples/llvm/st etc/llvm/st

#.include "../../lang/ocaml/buildlink3.mk"
TEST_TARGET=	check unittests

post-extract:
	${MV} ${WRKDIR}/clang ${WRKSRC}/tools/clang

# Get it from Subversion repository:
SVN_REPOSITORIES=	llvm clang
SVN_ROOT.llvm=		http://llvm.org/svn/llvm-project/llvm/trunk
SVN_MODULE.llvm=	llvm
SVN_ROOT.clang=		http://llvm.org/svn/llvm-project/cfe/trunk
SVN_MODULE.clang=	clang

PKGNAME=		clang-2.8.99
WRKSRC=			$(WRKDIR)/$(SVN_MODULE.llvm)

CHECK_PORTABILITY_SKIP= utils/buildit/.svn/text-base/build_llvm.svn-base \
			utils/buildit/build_llvm


.include "../../wip/mk/svn-package.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
