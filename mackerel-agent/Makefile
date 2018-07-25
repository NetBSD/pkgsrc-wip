# $NetBSD$

DISTNAME=	mackerel-agent-0.56.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackerelio/}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/mackerelio/mackerel-agent/
COMMENT=	Client software for Mackerel.io
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar
GO_SRCPATH=	github.com/mackerelio/${DISTNAME}
GOPATH=		${WRKDIR}
USE_TOOLS+=	gmake perl
BUILD_DEFS+=	VARBASE

MACKEREL_USER=	mackerelagent
MACKEREL_GROUP=	mackerelagent
PKG_GROUPS=	${MACKEREL_GROUP}
PKG_USERS=	${MACKEREL_USER}:${MACKEREL_GROUP}

INSTALLATION_DIRS+=	bin share/examples/mackerelagent

EGDIR=		${PREFIX}/share/examples/mackerelagent
CONF_FILES=	${EGDIR}/mackerelagent.sample.conf ${PKG_SYSCONFDIR}/mackerelagent.conf

MACKEREL_ROOTDIR=	${VARBASE}/lib/mackerelagent
MAKE_DIRS=		${MACKEREL_ROOTDIR}
MAKE_DIRS_PERMS=	${MACKEREL_ROOTDIR} ${MACKEREL_USER} ${MACKEREL_GROUP} 0755

RCD_SCRIPTS+=		mackerelagent

do-build:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH:Q}:${GOPATH}/bin ${MAKE_PROGRAM} build

do-test:
	cd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH:Q}:${GOPATH}/bin ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/mackerel-agent \
		${DESTDIR}${PREFIX}/bin/mackerelagent
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf \
		${DESTDIR}${EGDIR}/mackerelagent.sample.conf

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
