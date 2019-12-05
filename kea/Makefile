# $NetBSD$

DISTNAME=	kea-1.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/kea/${PKGVERSION_NOREV}/
MASTER_SITES+=	https://downloads.isc.org/isc/kea/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/kea/
COMMENT=	DHCP server from ISC
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=--with-openssl --enable-shell
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--localstatedir=${VARBASE}
PY_PATCHPLIST= 	yes

RCD_SCRIPTS+=	kea

EGDIR=		share/examples/kea
KEA_CONF=	kea-ctrl-agent.conf
KEA_CONF+=	kea-dhcp-ddns.conf
KEA_CONF+=	kea-dhcp4.conf
KEA_CONF+=	kea-dhcp6.conf
KEA_CONF+=	keactrl.conf

.for cf in ${KEA_CONF}
CONF_FILES+=	${EGDIR}/${cf} ${PKG_SYSCONFDIR}/kea/${cf}
.endfor

OWN_DIRS+=	${PKG_SYSCONFDIR}/kea
OWN_DIRS+=	${VARBASE}/run/kea
OWN_DIRS+=	${VARBASE}/lib/kea
OWN_DIRS+=	${VARBASE}/log

.include "options.mk"

.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
