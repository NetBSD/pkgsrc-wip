# $NetBSD: Makefile,v 1.1.1.1 2008/07/13 12:46:23 gschwarz Exp $

DISTNAME=	sipbomber_0.8
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://metalinkltd.com/wp-content/uploads/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.metalinkltd.com/downloads.php
COMMENT=	SipBomber is a SIP protocol testing tool

WRKSRC=		${WRKDIR}/${DISTNAME:C/_.*$//}
USE_LANGUAGES=	c c++
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

CXXFLAGS+=	-DQT_THREAD_SUPPORT -D_REENTRANT

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sipb_main ${PREFIX}/bin/sipbomber

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
