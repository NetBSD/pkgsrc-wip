# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:39 asau Exp $
#

GIT_SHA=	488ab66019f475e35e067646621827c18a879ba1
DISTNAME=	dzen-git-${GIT_SHA}
CATEGORIES=	x11 misc
MASTER_SITES=	-${HOMEPAGE}/archive/${GIT_SHA}.tar.gz
WRKSRC=		${WRKDIR}/dzen-${GIT_SHA}

MAINTAINER=	jake.slazenger@yandex.com
HOMEPAGE=	https://github.com/robm/dzen
COMMENT=	General purpose messaging and notification program
LICENSE=	mit

CONFLICTS+=	dzen2-[0-9]*

NO_CONFIGURE=		yes
BUILD_DIRS=		. gadgets

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gadgets/kittscanner.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gadgets/noisyalert.sh ${DESTDIR}${PREFIX}/bin

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
