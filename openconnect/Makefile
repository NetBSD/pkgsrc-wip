# $NetBSD: Makefile,v 1.6 2012/11/16 21:07:45 kristerw Exp $
#

DISTNAME=	openconnect-3.18
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect.html
COMMENT=	Client for Cisco AnyConnect VPN
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

DEPENDS+=	vpnc-script-[0-9]*:../../wip/vpnc-script

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-vpnc-script=${PKG_SYSCONFDIR}/vpnc-script
CONFIGURE_ARGS+=	--disable-nls

INSTALLATION_DIRS=	sbin include lib ${PKGMANDIR}/man8

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
