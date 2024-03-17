# $NetBSD$

DISTNAME=	forgejo-src-1.21.7-0
PKGNAME=	${DISTNAME:S/-src//S/-0/.0/}
CATEGORIES=	www devel
MASTER_SITES=	https://codeberg.org/forgejo/forgejo/releases/download/v${DISTNAME:S/forgejo-src-//}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forgejo.org/
COMMENT=	Git hosting software
LICENSE=	mit

INSTALLATION_DIRS=	share/example/forgejo

.include "../../lang/go/go-vars.mk"
.include "options.mk"

BUILD_DEFS+=	VARBASE FORGEJO_USER FORGEJO_GROUP

EXTRACT_USING=	bsdtar
USE_TOOLS+=	ggrep gmake pax tar
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

OWN_DIRS_PERMS+=	${VARBASE}/log/forgejo ${FORGEJO_USER} ${FORGEJO_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/db/forgejo ${FORGEJO_USER} ${FORGEJO_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/conf ${FORGEJO_USER} ${FORGEJO_GROUP} 0755

FORGEJO_USER?=	git
FORGEJO_GROUP?=	git

PKG_GROUPS_VARS+=	FORGEJO_GROUP
PKG_USERS_VARS+=	FORGEJO_USER

INSTALLATION_DIRS+=	sbin share/forgejo/options share/forgejo/templates share/forgejo/public share/examples/forgejo

RCD_SCRIPTS+=	forgejo

MAKE_ENV+=	TAGS="${GO_TAGS}"

do-build:
	cd ${WRKSRC} && \
		${BUILD_MAKE_CMD} ${BUILD_TARGET}

pre-install:
	${MV} ${WRKSRC}/gitea ${WRKSRC}/forgejo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/forgejo ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC}/options && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/options/
	cd ${WRKSRC}/templates && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/templates/
	cd ${WRKSRC}/public && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/public/
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/share/forgejo

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
