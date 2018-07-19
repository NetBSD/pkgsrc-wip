# $NetBSD$

DISTNAME=	cdirip-0.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jozip/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/jozip/cdirip/
COMMENT=	Program for extracting tracks from a CDI (DiscJuggler) image
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdirip ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
