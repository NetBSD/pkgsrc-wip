# $NetBSD: Makefile,v 1.21 2013/08/24 19:42:36 asau Exp $
#

DISTNAME=		open-axiom-1.4.1
PKGNAME=		openaxiom-1.4.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
# http://open-axiom.sourceforge.net/index.html
COMMENT=		Platform for symbolic, algebraic, and numerical computations

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GCC_REQD=		4.7	# C++11 is needed
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo awk:run
USE_LANGUAGES+=		fortran77
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

BUILD_MAKE_FLAGS+=	TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}

CONFIGURE_ENV+=		HOST_AWK=$(TOOLS_PATH.awk)	# force it

.include "options.mk"

# Fix version string
SUBST_CLASSES+=			version-string
SUBST_STAGE.version-string=	post-patch
SUBST_MESSAGE.version-string=	Fixing version string
SUBST_FILES.version-string=	configure.ac.pamphlet
SUBST_SED.version-string=	-e '/^AC_INIT(/s:[0-9.-]\{1,\}:${PKGVERSION_NOREV}:'

SUBST_CLASSES+=			version-string-2
SUBST_STAGE.version-string-2=	post-patch
SUBST_MESSAGE.version-string-2=	Fixing version string
SUBST_FILES.version-string-2=	configure
SUBST_SED.version-string-2=	-e '/^PACKAGE_VERSION=/s:[0-9.-]\{1,\}:${PKGVERSION_NOREV}:'
# PACKAGE_VERSION='1.3.0-2008-10-16'
# PACKAGE_STRING='OpenAxiom 1.3.0-2008-10-16'

pre-configure:
	${RUN} cd ${WRKSRC} && ./build-setup.sh

# Skip these checks for now:
CHECK_WRKREF_SKIP=	lib/*/hypertex lib/*/viewAlone lib/*/view2D lib/*/view3D lib/*/viewman


# Get it from Subversion repository:
SVN_REPOSITORIES=	open-axiom
SVN_REPO.open-axiom=	http://open-axiom.svn.sf.net/svnroot/open-axiom/trunk


WRKSRC=			${WRKDIR}/open-axiom

PKGNAME=		openaxiom-1.99	# VCS-based

.include "../mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
