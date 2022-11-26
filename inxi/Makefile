# $NetBSD$

DISTNAME=	inxi_3.3.01-1.orig
PKGNAME=	inxi-3.3.01
CATEGORIES=	sysutils
MASTER_SITES=	http://deb.debian.org/debian/pool/main/i/inxi/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://smxi.org/docs/inxi.htm
COMMENT=	full featured system information script
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/inxi-3.3.01-1

USE_TOOLS+=	perl
USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_PERL+=	inxi

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/inxi ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/inxi.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
