# $NetBSD$

DISTNAME=	suricata-8.0.8
CATEGORIES=	net security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://suricata.io/
COMMENT=	Fast open source network analysis and threat detection software
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gccmarch-native
CONFIGURE_ARGS+=	--enable-geoip
CONFIGURE_ARGS+=	--enable-hiredis
CONFIGURE_ARGS+=	--enable-libmagic
PKG_SYSCONFSUBDIR=	suricata

BUILD_DEFS+=	VARBASE
RCD_SCRIPTS+=	suricata
OWN_DIRS+=	${VARBASE}/log/suricata
OWN_DIRS+=	${VARBASE}/lib/suricata/cache/sgh
OWN_DIRS+=	${VARBASE}/lib/suricata/rules

EGDIR=		${PREFIX}/share/examples/suricata
CONF_FILES+=	${EGDIR}/classification.config ${PKG_SYSCONFDIR}/suricata/classification.config
CONF_FILES+=	${EGDIR}/reference.config ${PKG_SYSCONFDIR}/suricata/reference.config
CONF_FILES+=	${EGDIR}/suricata.yaml ${PKG_SYSCONFDIR}/suricata/suricata.yaml
CONF_FILES+=	${EGDIR}/threshold.config ${PKG_SYSCONFDIR}/suricata/threshold.config

INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} e_sysconfdir=${EGDIR}
INSTALL_TARGET=		install install-conf

.include "../../archivers/lz4/buildlink3.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
# not found by configure for some reason:
#.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
