# $NetBSD: Makefile,v 1.14 2012/09/29 00:50:34 asau Exp $

DISTNAME=	gforth-0.7.99
PKGNAME=	gforth-0.7.99 # needed because of cvs-package.mk
CATEGORIES=	lang

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=	Fast interpreter for the Forth language

GIT_REPOSITORIES=	gforth
GIT_REPO.gforth=	git://git.savannah.gnu.org/gforth.git

GNU_CONFIGURE=		yes
INFO_FILES=		yes

WRKSRC=		${WRKDIR}/gforth

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake aclocal
USE_TOOLS+=	makeinfo gzip
USE_TOOLS+=	perl:build
USE_TOOLS+=	gm4	# m4 regressed in NetBSD 5.99.21-22

MAKE_JOBS_SAFE=	no # fresh Gforth is required to build doc
BUILD_TARGET=	all info # doc
TEST_TARGET=	check

INSTALLATION_DIRS=	share/emacs/site-lisp

.include "../../mk/bsd.prefs.mk"
.if $(MACHINE_ARCH) == "amd64" ||  $(MACHINE_ARCH) == "x86_64"
PLIST_SUBST+=	BITS=64
.else
PLIST_SUBST+=	BITS=32
.endif

# Change package version to make it consistent with our scheme:
SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing package version.
SUBST_FILES.fix-version=	configure.in
SUBST_SED.fix-version=		-e '/^AC_INIT(/s/\[[-.0-9]*\]/[${PKGVERSION_NOREV}]/'
# AC_INIT([gforth],[0.7.0-20081226],[https://savannah.gnu.org/bugs/?func=addbug&group=gforth])

pre-configure:
	${RUN} cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libffcall/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
