# $NetBSD$

GITHUB_PROJECT=	strongswan
DISTNAME=	5.7.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=strongswan/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/strongswan/strongswan/
COMMENT=	strongSwan is an OpenSource IPsec-based VPN solution
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	autoconf automake perl flex bison gmake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv && automake

CONFIGURE_ARGS=	--enable-kernel-pfkey \
		--enable-kernel-pfroute  \
		--disable-kernel-netlink  \
		--disable-scripts  \
		--enable-openssl \
		--enable-eap-identity \
		--enable-eap-tls \
		--enable-eap-mschapv2 \
		--enable-eap-peap \
		--enable-eap-ttls \
		--enable-blowfish \
		--enable-addrblock \
		--enable-whitelist \
		--enable-cmd \
		--with-group=wheel

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
