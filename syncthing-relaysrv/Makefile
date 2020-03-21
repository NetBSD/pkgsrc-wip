# $NetBSD$

PKGNAME=	syncthing-relaysrv-1.3.3
PKGREVISION=	2
CATEGORIES=	net
DISTNAME=	syncthing-source-v1.3.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_PROJECT=	syncthing
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	izaac@setec.org
HOMEPAGE=	https://github.com/syncthing/relaysrv/
COMMENT=	Syncthing relay server
LICENSE=	mit

EXTRACT_USING=		bsdtar
BUILD_DEPENDS+=		go-[0-9]*:../../lang/go
NO_CONFIGURE=		yes
USE_LANGUAGES=		c # and go
GO_SRCPATH=		github.com/syncthing/syncthing
GO_DIST_BASE=		syncthing
INSTALLATION_DIRS=	bin

BUILD_DEFS+=			VARBASE
STRELAY_USER?=			strelay
STRELAY_GROUP?=			strelay
PKG_USERS_VARS=			STRELAY_USER
PKG_GROUPS_VARS=		STRELAY_GROUP
PKG_USERS=			${STRELAY_USER}:${STRELAY_GROUP}
PKG_GROUPS=			${STRELAY_GROUP}
PKG_GECOS.${STRELAY_USER}=	syncthing-relaysrv
PKG_HOME.${STRELAY_USER}=	${VARBASE}/chroot/strelay
OWN_DIRS_PERMS=			${PKG_HOME.${STRELAY_USER}} ${STRELAY_USER} ${STRELAY_GROUP} 0700

USE_TOOLS+=			pax
FILES_SUBST+=			INSTALL=${INSTALL}
FILES_SUBST+=			PAX=${PAX}
FILES_SUBST+=			PKG_HOME=${PKG_HOME.${STRELAY_USER}}
FILES_SUBST+=			STRELAY_GROUP=${STRELAY_GROUP}
FILES_SUBST+=			STRELAY_USER=${STRELAY_USER}
RCD_SCRIPTS=			strelay

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} run build.go build strelaysrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strelaysrv ${DESTDIR}${PREFIX}/bin/syncthing-relaysrv

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
