# $NetBSD: Makefile,v 1.28 2013/07/09 14:10:18 noud4 Exp $
#

DISTNAME=	httrack-3.49.2
CATEGORIES=	www
MASTER_SITES=	http://download.httrack.com/cserv.php3?File= \
		http://mirror.httrack.com/historical/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.httrack.com/
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

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	src/htsweb.c
SUBST_SED.path=		-e "s|/usr/share/httrack/|${PREFIX}/share/httrack/|"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
