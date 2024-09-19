# $NetBSD$

DISTNAME=	rainbow_${PORTVERSION}
PKGNAME=	rainbow-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bio-rainbow/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/bio-rainbow/
COMMENT=	Short reads clustering and local assembly
LICENSE=	gnu-gpl-v3

PORTVERSION=	2.0.4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/rainbow \
		${WRKSRC}/ezmsim \
		${WRKSRC}/rbasm \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
