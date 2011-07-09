# $NetBSD: Makefile,v 1.2 2011/07/09 17:38:45 asau Exp $

DISTNAME=	clang-2.9.99
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/llvm

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake perl:build chown
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-assertions
CONFIGURE_ARGS+=	--disable-bindings	# disable OCaml
CONFIGURE_ARGS+=	--disable-timestamps
CONFIGURE_ARGS+=	--enable-optimized

MAKE_DIRS+=		etc/llvm

INSTALLATION_DIRS=	bin lib libexec


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

CHECK_PORTABILITY_SKIP= utils/buildit/.svn/text-base/build_llvm.svn-base \
			utils/buildit/build_llvm


.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
