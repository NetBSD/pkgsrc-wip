# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 14:05:47 gschwarz Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	 bin sbin

do-build:
		cd ${WRKSRC} &&  \
		${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} cUDPingLnx.cpp -o udp-ping ${LIBS} && \
		${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} sUDPingLnx.cpp -o udp-ping-server ${LIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/udp-ping ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} ${WRKSRC}/udp-ping-server ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
