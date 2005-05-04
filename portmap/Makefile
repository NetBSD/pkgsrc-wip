# $NetBSD: Makefile,v 1.7 2005/05/04 01:17:04 jeremy-c-reed Exp $

DISTNAME= 	portmap_4
PKGNAME=	portmap-4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	RPC portmapper with access control

# XXX allow this to install on NetBSD, because this also
# XXX provides pmap_dump and pmap_set

INSTALLATION_DIRS+=	sbin share/doc/portmap
MAKE_FLAGS+=	WRAP_DIR=${BUILDLINK_PREFIX.tcp_wrappers}/lib
NO_CONFIGURE=	yes
RCD_SCRIPTS=	portmap
USE_PKGINSTALL=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portmap ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_dump ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/pmap_set ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/portmap/

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
