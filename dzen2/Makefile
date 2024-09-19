# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:39 asau Exp $
#

DISTNAME=	dzen2-0.8.5
PKGREVISION=	2
CATEGORIES=	x11 misc
MASTER_SITES=	http://gotmor.googlepages.com/

MAINTAINER=	pikapika@8-0.net
HOMEPAGE=	https://sites.google.com/site/gotmor/dzen
COMMENT=	General purpose messaging and notification program
LICENSE=	mit

NO_CONFIGURE=		yes
BUILD_DIRS=		. gadgets

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gadgets/kittscanner.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gadgets/noisyalert.sh ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
