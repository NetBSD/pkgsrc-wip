# $NetBSD: Makefile,v 1.5 2004/04/25 08:25:47 blef Exp $

DISTNAME= 	portmap_4
PKGNAME=	portmap-4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	RPC portmapper with access control

# XXX allow this to install on NetBSD, because this also
# XXX provides pmap_dump and pmap_set

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
USE_PKGINSTALL=	yes

MAKE_FLAGS+=	WRAP_DIR=${BUILDLINK_PREFIX.tcp_wrappers}/lib

RCD_SCRIPTS=	portmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portmap ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_dump ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_set ${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/portmap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/portmap/

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
