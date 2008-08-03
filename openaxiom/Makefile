# $NetBSD: Makefile,v 1.4 2008/08/03 10:17:01 asau Exp $
#

DISTNAME=		open-axiom-1.1.0
PKGNAME=		open-axiom-1.1.99	# VCS-based
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
# http://open-axiom.sourceforge.net/index.html
COMMENT=		Platform for symbolic, algebraic, and numerical computations

# Get it from Subversion repository:
SVN_REPOSITORIES=	open-axiom
SVN_ROOT.open-axiom=	https://open-axiom.svn.sf.net/svnroot/open-axiom/trunk
SVN_MODULE.open-axiom=	open-axiom

WRKSRC=			${WRKDIR}/open-axiom

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gawk makeinfo
USE_LANGUAGES+=		fortran
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb
#INFO_FILES=		yes

BUILD_MAKE_FLAGS+=	TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}

#USE_GNU_CONFIGURE_HOST=	no

#TARGET_SYSTEM!=		../../mk/gnu-config/config.guess
#PLIST_SUBST+=		TARGET_SYSTEM=${TARGET_SYSTEM}

.include "options.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ./build-setup.sh

# I need to figure out, why it fails with pkgsrc's version:
# do-configure:
# 	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS} # --prefix=/usr/pkg

.include "../mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
