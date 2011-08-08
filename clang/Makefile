# $NetBSD: Makefile,v 1.9 2011/08/08 14:15:12 asau Exp $

DISTNAME=	llvm-2.6
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-wip-discuss@lists.sourceforge.net
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

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST_SUBST+=		SOEXT="so"
.endif
PLIST_SUBST+=		PLIST_PKGVERSION=3.0 	# already used for current

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing llvm-configure PERL path
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	tools/llvm-config/llvm-config.in.in
SUBST_SED.perl=		-e 's,@PERL@,${PERL5},'

post-extract:
	${MV} ${WRKDIR}/clang ${WRKSRC}/tools/clang

# Get it from Subversion repository:
SVN_REPOSITORIES=	llvm clang
SVN_ROOT.llvm=		http://llvm.org/svn/llvm-project/llvm/trunk
SVN_ROOT.clang=		http://llvm.org/svn/llvm-project/cfe/trunk

PKGNAME=		clang-2.8.99
WRKSRC=			$(WRKDIR)/$(SVN_MODULE.llvm)

CHECK_PORTABILITY_SKIP= utils/buildit/.svn/text-base/build_llvm.svn-base \
			utils/buildit/build_llvm


.include "../../wip/mk/svn-package.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
