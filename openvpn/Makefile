# $NetBSD: Makefile,v 1.7 2004/01/15 22:11:12 dawszy Exp $
#

DISTNAME=		openvpn-1.5.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=		tripledes@eslack.org
HOMEPAGE=		http://openvpn.sourceforge.net/
COMMENT=		Robust and highly configurable VPN

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+= 	--enable-pthread

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openvpn
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/config
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/keys
	for f in AUTHORS COPYING COPYRIGHT.GPL ChangeLog NEWS PORTS README; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/openvpn; \
	done
	for f in ${WRKSRC}/sample-config-files/*; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/openvpn/config; \
	done
	for f in ${WRKSRC}/sample-keys/*; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/openvpn/keys; \
	done

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
