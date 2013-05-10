# $NetBSD: Makefile,v 1.27 2013/05/10 07:57:09 ahp-nils Exp $
#

DISTNAME=	httrack-3.47.11
CATEGORIES=	www
MASTER_SITES=	http://download.httrack.com/cserv.php3?File=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
LDFLAGS+=		-L${WRKSRC}/src/.libs/
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		bash:run gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

REPLACE_BASH=		src/webhttrack

SUBST_CLASSES+=		html
SUBST_STAGE.html=	pre-install
SUBST_FILES.html=	html/Makefile
SUBST_SED.html=		-e 's,install-data-hook,,'

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
