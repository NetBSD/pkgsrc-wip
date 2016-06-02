# $NetBSD$

PKGNAME=	syncthing-discosrv-0.13.0
PKGREVISION=	1
CATEGORIES=	local
DISTNAME=	syncthing-discosrv-0.13.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_PROJECT=	discosrv
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	izaac@setec.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=syncthing/discosrv/}
COMMENT=	Syncthing discovery server
LICENSE=	mit

WRKSRC=			${WRKDIR}/discosrv-0.13.0
BUILD_DEPENDS+=		go-[0-9]*:../../lang/go
NO_CONFIGURE=		yes
USE_LANGUAGES= 		c # and go
INSTALLATION_DIRS=	bin

BUILD_DEFS+=                    VARBASE
STDISCO_USER?=                  stdisco
STDISCO_GROUP?=                 stdisco
PKG_USERS_VARS=                 STDISCO_USER
PKG_GROUPS_VARS=                STDISCO_GROUP
PKG_USERS=                      ${STDISCO_USER}:${STDISCO_GROUP}
PKG_GROUPS=                     ${STDISCO_GROUP}
PKG_GECOS.${STDISCO_USER}=      syncthing-discosrv
PKG_HOME.${STDISCO_USER}=       ${VARBASE}/chroot/stdisco
OWN_DIRS_PERMS=                 ${PKG_HOME.${STDISCO_USER}} ${STDISCO_USER} ${STDISCO_GROUP} 0700

USE_TOOLS+=                     pax
FILES_SUBST+=                   INSTALL=${INSTALL}
FILES_SUBST+=                   PAX=${PAX}
FILES_SUBST+=                   PKG_HOME=${PKG_HOME.${STDISCO_USER}}
FILES_SUBST+=                   STDISCO_GROUP=${STDISCO_GROUP}
FILES_SUBST+=                   STDISCO_USER=${STDISCO_USER}
RCD_SCRIPTS=                    stdisco

MAKE_ENV+=	GOPATH=${WRKSRC}

do-build:
	cd ${WRKSRC} && ${MV} vendor src && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go build -i -v -ldflags -w

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/discosrv-0.13.0 ${DESTDIR}${PREFIX}/bin/syncthing-discosrv

.include "../../mk/bsd.pkg.mk"
