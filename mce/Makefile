# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:53 asau Exp $
#

DISTNAME=	mce-dev_1.5.6.debian.orig
PKGNAME=	mce-1.5.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/mce-dev/}

MAINTAINER=	kamel.derouiche@gmail.com
COMMENT=	The DBus method calls provided by the Mode Control Entity
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/mce-dev-1.5.6.debian.orig

NO_BUILD=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	include/mce lib/pkgconfig/

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr,${PREFIX},g'
SUBST_FILES.paths+=	mce.pc
SUBST_MESSAGE.paths=	Fixing header search paths.

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/mce/*.h \
			${DESTDIR}${PREFIX}/include/mce/
	${INSTALL_DATA} ${WRKSRC}/mce.pc \
			${DESTDIR}${PREFIX}/lib/pkgconfig/

.include "../../mk/bsd.pkg.mk"
