# $NetBSD$

PKGNAME=	syncthing-discosrv-1.3.3
PKGREVISION=	2
CATEGORIES=	net
DISTNAME=	syncthing-source-v1.3.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_PROJECT=	syncthing
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	izaac@setec.org
HOMEPAGE=	https://github.com/syncthing/discosrv/
COMMENT=	Syncthing discovery server
LICENSE=	mit

EXTRACT_USING=		bsdtar
BUILD_DEPENDS+=		go-[0-9]*:../../lang/go
NO_CONFIGURE=		yes
USE_LANGUAGES=		c # and go
GO_SRCPATH=		github.com/syncthing/syncthing
GO_DIST_BASE=		syncthing
INSTALLATION_DIRS=	bin

BUILD_DEFS+=			VARBASE
STDISCO_USER?=			stdisco
STDISCO_GROUP?=			stdisco
PKG_USERS_VARS=			STDISCO_USER
PKG_GROUPS_VARS=		STDISCO_GROUP
PKG_USERS=			${STDISCO_USER}:${STDISCO_GROUP}
PKG_GROUPS=			${STDISCO_GROUP}
PKG_GECOS.${STDISCO_USER}=	syncthing-discosrv
PKG_HOME.${STDISCO_USER}=	${VARBASE}/chroot/stdisco
OWN_DIRS_PERMS=			${PKG_HOME.${STDISCO_USER}} ${STDISCO_USER} ${STDISCO_GROUP} 0700

USE_TOOLS+=			pax
FILES_SUBST+=			INSTALL=${INSTALL}
FILES_SUBST+=			PAX=${PAX}
FILES_SUBST+=			PKG_HOME=${PKG_HOME.${STDISCO_USER}}
FILES_SUBST+=			STDISCO_GROUP=${STDISCO_GROUP}
FILES_SUBST+=			STDISCO_USER=${STDISCO_USER}
RCD_SCRIPTS=			stdisco

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} run build.go build stdiscosrv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stdiscosrv ${DESTDIR}${PREFIX}/bin/syncthing-discosrv

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
