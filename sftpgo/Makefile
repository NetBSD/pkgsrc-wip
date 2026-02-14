# $NetBSD$

DISTNAME=		sftpgo-2.7.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=drakkan/}
GITHUB_TAG=		refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://github.com/drakkan/sftpgo/
COMMENT=		Event-driven SFTP, FTP/S, HTTP/S and WebDAV server
LICENSE=		gnu-gpl-v3

WRKSRC=			${WRKDIR}/${DISTNAME}

EGDIR=			${PREFIX}/share/examples/sftpgo
USE_LANGUAGES=		c
USE_TOOLS=		tar

DEPENDS+=		daemonize>=1.7.8:../../sysutils/daemonize

GO_BUILD_PATTERN=

CONF_FILES=		${EGDIR}/sftpgo.json ${PKG_SYSCONFDIR}/sftpgo.json
INSTALLATION_DIRS=	share/sftpgo
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/sftpgo

SFTPGO_USER?=		sftpgo
SFTPGO_GROUP?=		sftpgo
PKG_GROUPS=		${SFTPGO_GROUP}
PKG_USERS=		${SFTPGO_USER}:${SFTPGO_GROUP}
PKG_GROUPS_VARS=	SFTPGO_USER
PKG_USERS_VARS=		SFTPGO_GROUP

OWN_DIRS_PERMS=		${VARBASE}/sftpgo \
				${SFTPGO_USER} ${SFTPGO_GROUP} 0700

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		set-path
SUBST_STAGE.set-path=	post-build
SUBST_MESSAGE.set-path=	Set path in configuration file
SUBST_FILES.set-path=	sftpgo.json
SUBST_SED.set-path=	-e 's|"openapi"|"${PREFIX}/share/sftpgo/openapi"|g'
SUBST_SED.set-path+=	-e 's|"static"|"${PREFIX}/share/sftpgo/static"|g'
SUBST_SED.set-path+=	-e 's|"templates"|"${PREFIX}/share/sftpgo/templates"|g'

RCD_SCRIPTS+=		sftpgo
FILES_SUBST+=		SFTPGO_USER=${SFTPGO_USER:Q}

.include "go-modules.mk"

post-build:
	${WRKDIR}/.gopath/bin/sftpgo gen man --dir ${WRKDIR}/man

post-install:
	${INSTALL_MAN} ${WRKDIR}/man/*.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

	${INSTALL_DATA} ${WRKSRC}/sftpgo.json \
		${DESTDIR}${EGDIR}

	${TAR} -cf - -C ${WRKSRC} openapi | \
		${TAR} -xf - -C ${DESTDIR}${PREFIX}/share/sftpgo
	${TAR} -cf - -C ${WRKSRC} static | \
		${TAR} -xf - -C ${DESTDIR}${PREFIX}/share/sftpgo
	${TAR} -cf - -C ${WRKSRC} templates | \
		${TAR} -xf - -C ${DESTDIR}${PREFIX}/share/sftpgo

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
