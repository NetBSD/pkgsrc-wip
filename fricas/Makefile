# $NetBSD: Makefile,v 1.8 2008/02/29 22:14:16 asau Exp $
#

PKGNAME=		fricas-1.0.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
DISTNAME=		fricas-1.0.2-full
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/index.html
COMMENT=		FriCAS is an advanced computer algebra system.

WRKSRC=			${WRKDIR}/${PKGNAME}

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gawk makeinfo
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb
#INFO_FILES=		yes

USE_GNU_CONFIGURE_HOST=	no

TARGET_SYSTEM!=		../../mk/gnu-config/config.guess
PLIST_SUBST+=		TARGET_SYSTEM=${TARGET_SYSTEM}

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

.include "options.mk"

# I need to figure out, why it fails with pkgsrc's version:
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS}

# I need to figure out, why it doesn't install that file,
# it ends in endless loop trying to exec that "viewman" file:
post-install:
	echo exit 0 > ${DESTDIR}${PREFIX}/lib/fricas/target/${TARGET_SYSTEM}/lib/viewman
	chmod +x ${DESTDIR}${PREFIX}/lib/fricas/target/${TARGET_SYSTEM}/lib/viewman

.include "../../mk/bsd.pkg.mk"
