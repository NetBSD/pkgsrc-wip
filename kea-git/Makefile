# $NetBSD$

PKGNAME=	kea-git-1.9
CATEGORIES=	net
GIT_REPO=	https://gitlab.isc.org/isc-projects/kea.git
GIT_ENV=	GIT_SSL_NO_VERIFY=true

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/kea/
COMMENT=	DHCP servers from ISC
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	autoconf automake bash:run bison flex

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-shell
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-generate-parser

BUILDLINK_TRANSFORM+=	rm:-Woverloaded-virtual

PY_PATCHPLIST=	yes

RCD_SCRIPTS+=	kea

REPLACE_BASH+=	src/bin/keactrl/keactrl.in

EGDIR=		share/examples/kea
KEA_CONF=	kea-ctrl-agent.conf
KEA_CONF+=	kea-dhcp-ddns.conf
KEA_CONF+=	kea-dhcp4.conf
KEA_CONF+=	kea-dhcp6.conf
KEA_CONF+=	keactrl.conf

.for cf in ${KEA_CONF}
CONF_FILES+=	${EGDIR}/${cf} ${PKG_SYSCONFDIR}/kea/${cf}
.endfor

# this can be used after building to run the unit tests
run_kea_unittests:
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} check


OWN_DIRS+=	${PKG_SYSCONFDIR}/kea
OWN_DIRS+=	${VARBASE}/run/kea
OWN_DIRS+=	${VARBASE}/lib/kea
OWN_DIRS+=	${VARBASE}/log

pre-configure:
	cd ${WRKSRC} && autoreconf -i


.include "options.mk"

PLIST_VARS+=	bpf
.if !(${OPSYS} == "Linux")
PLIST.bpf=	yes
.endif

.include "../../wip/mk/git-package.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
