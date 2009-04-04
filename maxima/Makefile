# $NetBSD: Makefile,v 1.15 2009/04/04 15:12:16 asau Exp $
#

PKGNAME=		maxima-5.17.99
DISTNAME=		maxima-5.17.1
# On updates, please make sure editors/TeXmacs knows about the new
# version number.
# (if needed, patch plugins/maxima/bin/{maxima_detect,tm_maxima})
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system

CVS_REPOSITORIES=	maxima
CVS_ROOT.maxima=	:pserver:anonymous:@maxima.cvs.sourceforge.net:/cvsroot/maxima
WRKSRC=		${WRKDIR}/maxima

# Note: lisp backend is depended and setup up for in options.mk
DEPENDS+=		tk-[0-9]*:../../x11/tk

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		aclocal automake autoconf
USE_TOOLS+=		makeinfo perl
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check

.include "options.mk"

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing package version.
SUBST_FILES.fix-version=	configure.in
SUBST_SED.fix-version=		-e 's:AM_INIT_AUTOMAKE(maxima,[^)]*):AM_INIT_AUTOMAKE(maxima,${PKGVERSION_NOREV}):'

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
