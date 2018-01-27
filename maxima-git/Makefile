# $NetBSD: Makefile,v 1.36 2013/10/09 19:02:17 asau Exp $

DISTNAME=		maxima-5.27.0
# On updates, please make sure editors/TeXmacs knows about the new
# version number.
# (if needed, patch plugins/maxima/bin/{maxima_detect,tm_maxima})
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system
LICENSE=		gnu-gpl-v2

# Note: lisp backend is depended and setup up for in options.mk
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo perl
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check

.include "options.mk"

# Section for VCS-based package:

PKGNAME=		maxima-5.99

GIT_REPOSITORIES=	maxima
GIT_REPO.maxima=	git://maxima.git.sourceforge.net/gitroot/maxima/maxima

WRKSRC=		${WRKDIR}/maxima

USE_TOOLS+=		aclocal automake autoconf

CONFIGURE_ENV+=		VERSION=$(PKGVERSION_NOREV) ac_cv_prog_git_found=false

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing package version.
SUBST_FILES.fix-version=	configure.in
SUBST_SED.fix-version=		-e 's:AC_INIT(\[maxima\], *\[.*\]):AC_INIT([maxima],[${PKGVERSION_NOREV}]):'

PYTHON_FOR_BUILD_ONLY=	yes
ALL_ENV+=		PYTHONBIN=$(PYTHONBIN:Q)

pre-configure:
	cd ${WRKSRC}/src && ${CONFIG_SHELL} ../admin/make_share_list
	cd ${WRKSRC} && ./bootstrap

.include "../../wip/mk/git-package.mk"

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
