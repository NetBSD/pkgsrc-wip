# $NetBSD: Makefile,v 1.1.1.1 2009/01/21 22:42:09 gschwarz Exp $

DISTNAME=	tctool-0.9.7
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/speedmodem50b/ \
		http://download2.berlios.de/speedmodem50b/
EXTRACT_SUFX=	.zip

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://speedmodem50b.berlios.de/
COMMENT=	Speed Modem 50B/50B+/200/Cellpipe CELL 19A-BX utility

#LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGBASE}/src
NO_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
INSTALLATION_DIRS=	bin

BUILD_TARGET=	tctool

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/tctool ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
