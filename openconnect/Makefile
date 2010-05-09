# $NetBSD: Makefile,v 1.1.1.1 2010/05/09 07:28:22 pdtafti Exp $
#

DISTNAME=	openconnect-2.24
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.infradead.org/openconnect.html
COMMENT=	Client for Cisco AnyConnect VPN
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= 		gmake

DEPENDS+=			vpnc-script:../../wip/vpnc-script

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/doc/openconnect

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openconnect ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/openconnect.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README.SecurID ${DESTDIR}${PREFIX}/share/doc/openconnect
	${INSTALL_DATA} ${WRKSRC}/openconnect.html ${DESTDIR}${PREFIX}/share/doc/openconnect

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
