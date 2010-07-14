# $NetBSD: Makefile,v 1.13 2010/07/14 09:03:39 asau Exp $

DISTNAME=	gforth-0.7.99
PKGNAME=	gforth-0.7.99 # needed because of cvs-package.mk
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gforth/} \
		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=	Fast interpreter for the Forth language

CVS_REPOSITORIES=	gforth
CVS_ROOT.gforth=	:pserver:anonymous:@c1.complang.tuwien.ac.at:/nfs/unsafe/cvs-repository/src-master

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../devel/ffcall/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
