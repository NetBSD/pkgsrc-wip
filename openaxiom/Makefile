# $NetBSD: Makefile,v 1.2 2008/03/14 14:25:23 asau Exp $
#

DISTNAME=		open-axiom-1.1.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
# http://open-axiom.sourceforge.net/index.html
COMMENT=		Platform for symbolic, algebraic, and numerical computations

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gawk makeinfo
USE_LANGUAGES+=		fortran
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb
#INFO_FILES=		yes

#USE_GNU_CONFIGURE_HOST=	no

#TARGET_SYSTEM!=		../../mk/gnu-config/config.guess
#PLIST_SUBST+=		TARGET_SYSTEM=${TARGET_SYSTEM}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ${RUN} ./build-setup.sh

# I need to figure out, why it fails with pkgsrc's version:
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS} # --prefix=/usr/pkg

.include "../../mk/bsd.pkg.mk"
