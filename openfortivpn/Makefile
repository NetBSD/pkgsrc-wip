# $NetBSD$
DISTNAME=	openfortivpn-1.17.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=adrienverge/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tsao@disroot.org
HOMEPAGE=	https://github.com/adrienverge/openfortivpn/
COMMENT=	Client for PPP+SSL VPN tunnel services, compatible with Fortinet VPNs
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		aclocal autoconf automake gmake pkg-config awk gsed
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
BUILD_DEFS+=		PKG_SYSCONFBASE
CONF_FILES+=		${PREFIX}/share/examples/${PKGNAME}/config ${PKG_SYSCONFDIR}/openfortivpn/config
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openfortivpn \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"

pre-configure:
	set -e && cd ${WRKSRC} && ./autogen.sh
post-install:
	set -e && mkdir -p ${DESTDIR}${PREFIX}/share/examples/${PKGNAME} && \
	mv ${DESTDIR}${PKG_SYSCONFBASE}/openfortivpn/config ${DESTDIR}${PREFIX}/share/examples/${PKGNAME}/config

.include "../../mk/bsd.pkg.mk"
