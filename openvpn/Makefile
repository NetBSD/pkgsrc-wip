# 
# $NetBSD: Makefile,v 1.4 2003/06/29 09:53:13 cjep Exp $
#

DISTNAME=		openvpn-1.4.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=		tripledes@eslack.org
HOMEPAGE=		http://openvpn.sourceforge.net/
COMMENT=		Robust and highly configurable VPN

GNU_CONFIGURE=          yes
USE_PKGINSTALL=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS+= 	--enable-pthread

DOC_FILES=		AUTHORS COPYING COPYRIGHT.GPL ChangeLog NEWS PORTS README
SAMPLE_FILES=		sample-config-files sample-keys

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openvpn
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/config
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/openvpn/keys

	for docfiles in ${DOC_FILES}; do					 \
		${INSTALL_DATA} ${WRKSRC}/$$docfiles ${PREFIX}/share/doc/openvpn;\
	done

	${INSTALL_DATA} ${WRKSRC}/sample-config-files/* ${PREFIX}/share/examples/openvpn/config
	${INSTALL_DATA} ${WRKSRC}/sample-keys/* ${PREFIX}/share/examples/openvpn/keys

.include "../../security/openssl/buildlink2.mk"
.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
