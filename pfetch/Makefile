# $NetBSD$

DISTNAME=	pfetch-0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/pfetch
COMMENT=	Pretty system information tool written in POSIX sh
LICENSE=	mit

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin share/doc/pfetch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.md \
		${DESTDIR}${PREFIX}/share/doc/pfetch/LICENSE.md

.include "../../mk/bsd.pkg.mk"
