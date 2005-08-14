# $NetBSD: Makefile,v 1.2 2005/08/14 08:35:17 thomasklausner Exp $

DISTNAME=	sipp.1.0
PKGNAME=	sipp-1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipp/}

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://sipp.sourceforge.net
COMMENT=	SIPp is a free Open Source SIP test tool/traffic generator

WRKSRC=		${WRKDIR}/sipp
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
MAKE_ENV+=	PKGSRC_CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sipp ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
