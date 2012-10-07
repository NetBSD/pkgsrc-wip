# $NetBSD: Makefile,v 1.9 2012/10/07 16:23:06 asau Exp $

DISTNAME=	sipbomber_0.8
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.sourcefiles.org/Internet/Communications/Telephony/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.sourcefiles.org/Internet/Communications/Telephony/sipbomber_0.8.tar.gz.shtml
COMMENT=	SipBomber is a SIP protocol testing tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:C/_.*$//}
USE_LANGUAGES=	c c++
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

CXXFLAGS+=	-DQT_THREAD_SUPPORT -D_REENTRANT
LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:Q}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/sipb_main ${DESTDIR}${PREFIX}/bin/sipbomber

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
