# $NetBSD: Makefile,v 1.25 2012/09/29 17:05:57 asau Exp $
#

DISTNAME=	httrack-3.43-5
PKGNAME=	httrack-3.43.5
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
LDFLAGS+=		-L${WRKSRC}/src/.libs/
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_LIBTOOL=		yes
USE_TOOLS+=		bash:run gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

REPLACE_BASH=		src/webhttrack

SUBST_CLASSES+=		html
SUBST_STAGE.html=	pre-install
SUBST_FILES.html=	html/Makefile
SUBST_SED.html=		-e 's,install-data-hook,,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
