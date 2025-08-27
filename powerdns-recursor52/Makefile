# $NetBSD$

DISTNAME=	pdns-recursor-5.2.5
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.bz2
PKGNAME=	powerdns-recursor-5.2.5

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://downloads.powerdns.com/releases/
COMMENT=	PowerDNS resolver
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libsodium
CONFIGURE_ARGS+=	--enable-dns-over-tls

CHECK_WRKREF_SKIP+=	sbin/pdns_recursor

EGDIR=			${PREFIX}/share/examples/powerdns-recursor52
CONF_FILES=		${EGDIR}/recursor.yml-dist ${PKG_SYSCONFDIR}/recursor.yml
INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

RCD_SCRIPTS=		pdns_recursor

SMF_NAME=		pdns-recursor
SMF_METHODS=		pdns_recursor


.include "cargo-depends.mk"
.include "cargo.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

