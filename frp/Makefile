# $NetBSD$

DISTNAME=	frp-0.48.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=fatedier/}
CATEGORIES=	net
DIST_SUBDIR=    ${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/fatedier/frp
COMMENT=	Reverse proxy to expose local server behind NAT/firewall to Internet
LICENSE=	apache-2.0

GO_SRCPATH=		github.com/fatedier/frp
GO_BUILD_PATTERN=	${GO_SRCPATH}/cmd/frps ${GO_SRCPATH}/cmd/frpc
PKG_SYSCONFSUBDIR=	${PKGBASE}
RCD_SCRIPTS+=		frps

CONF_FILES+=		${DESTDIR}${PREFIX}/share/examples/frp/frpc.ini.sample \
			${DESTDIR}${PREFIX}/share/examples/frp/frps.ini.sample

BUILD_DEFS+=		FRP_USER FRP_GROUP

.include "../../mk/bsd.prefs.mk"

FRP_USER?=		nobody
FRP_GROUP?=		nobody
PKG_GROUPS+=		${FRP_GROUP}
PKG_USERS+=		${FRP_USER}:${FRP_GROUP}
PKG_GROUPS_VARS+=	FRP_GROUP
PKG_USERS_VARS+=	FRP_USER

FILES_SUBST+=		FRP_USER=${FRP_USER}
FILES_SUBST+=		FRP_GROUP=${FRP_GROUP}

INSTALLATION_DIRS+=	sbin libexec share/examples/frp

CHECK_PIE_SKIP=		sbin/frpc sbin/frps
CHECK_RELRO_SKIP=	sbin/frpc sbin/frps

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/frps ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/frpc ${DESTDIR}${PREFIX}/sbin

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/frpc_full.ini ${DESTDIR}${PREFIX}/share/examples/frp/frpc.ini.sample
	${INSTALL_DATA} ${WRKSRC}/conf/frps_full.ini ${DESTDIR}${PREFIX}/share/examples/frp/frps.ini.sample

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
