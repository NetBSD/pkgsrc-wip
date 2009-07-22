# $NetBSD: Makefile,v 1.24 2009/07/22 09:53:13 thomasklausner Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

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
