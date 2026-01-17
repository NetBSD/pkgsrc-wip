# $NetBSD$

DISTNAME=	forgejo-src-14.0.0
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	www devel
MASTER_SITES=	https://codeberg.org/forgejo/forgejo/releases/download/v${DISTNAME:S/forgejo-src-//}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forgejo.org/
COMMENT=	Git hosting software
LICENSE=	mit

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../lang/go/go-vars.mk"
.include "options.mk"

BUILD_DEFS+=	VARBASE FORGEJO_USER FORGEJO_GROUP

EXTRACT_USING=	bsdtar
USE_TOOLS+=	ggrep gmake pax tar

OWN_DIRS_PERMS+=	${VARBASE}/log/forgejo ${FORGEJO_USER} ${FORGEJO_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/db/forgejo ${FORGEJO_USER} ${FORGEJO_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/conf ${FORGEJO_USER} ${FORGEJO_GROUP} 0755

FORGEJO_USER?=	git
FORGEJO_GROUP?=	git

PKG_GROUPS_VARS+=	FORGEJO_GROUP
PKG_USERS_VARS+=	FORGEJO_USER

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	share/forgejo/options
INSTALLATION_DIRS+=	share/forgejo/templates
INSTALLATION_DIRS+=	share/forgejo/public
INSTALLATION_DIRS+=	share/examples/forgejo

RCD_SCRIPTS+=	forgejo

MAKE_ENV+=	TAGS="${GO_TAGS}"

do-build:
	cd ${WRKSRC} && \
		${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitea ${DESTDIR}${PREFIX}/sbin/forgejo
	cd ${WRKSRC}/options && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/options/
	cd ${WRKSRC}/templates && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/templates/
	cd ${WRKSRC}/public && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/forgejo/public/
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/share/forgejo

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
