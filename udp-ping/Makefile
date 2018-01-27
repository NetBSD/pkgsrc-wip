# $NetBSD: Makefile,v 1.3 2012/10/07 17:41:39 asau Exp $

DISTNAME=	udp-ping
PKGNAME=	${DISTNAME}-1.0
CATEGORIES=	net
MASTER_SITES=	http://perform.wpi.edu/downloads/udp-tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://perform.wpi.edu/tools/
COMMENT=	UDP Ping is a tool to selectively send UDP packets

WRKSRC=		${WRKDIR}/UDPing
USE_LANGUAGES=	c++
NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	bin sbin

do-build:
		cd ${WRKSRC} &&  \
		${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} ${PTHREAD_LDFLAGS} cUDPingLnx.cpp -o udp-ping ${LIBS} ${PTHREAD_LIBS} && \
		${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} sUDPingLnx.cpp -o udp-ping-server ${LIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/udp-ping ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} ${WRKSRC}/udp-ping-server ${DESTDIR}${PREFIX}/sbin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
