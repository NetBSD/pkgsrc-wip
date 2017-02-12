# $NetBSD$
# vim: noexpandtab:

GITHUB_PROJECT=	cdirip
DISTNAME=	cdirip-0.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jozip/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tr@vispaul.me
HOMEPAGE=	https://github.com/jozip/cdirip/
COMMENT=	Program for extracting tracks from a CDI (DiscJuggler) image
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdirip ${DESTDIR}${PREFIX}/bin

WRKSRC=	${WRKDIR}/cdirip-0.6.3

.include "../../mk/bsd.pkg.mk"
