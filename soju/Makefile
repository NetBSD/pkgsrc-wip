# $NetBSD$

DISTNAME=	soju-${VERSION}
VERSION=	0.8.1
CATEGORIES=	chat
MASTER_SITES=	https://codeberg.org/emersion/soju/releases/download/v${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://soju.im/
COMMENT=	User friendly IRC bouncer
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	scdoc>=0:../../textproc/scdoc

BUILD_DEFS+=	VARBASE

GO_BUILD_PATTERN+=	-ldflags ' \
			-X codeberg.org/emersion/soju/config.DefaultPath=${PKG_SYSCONFDIR}/config \
			-X codeberg.org/emersion/soju/config.DefaultUnixAdminPath=${VARBASE}/run/soju/admin'
GO_BUILD_PATTERN+=	./cmd/soju ./cmd/sojuctl ./cmd/sojudb \
			./contrib/migrate-db ./contrib/migrate-logs \
			./contrib/znc-import

DOCDIR=			${PREFIX}/share/doc/soju
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PREFIX}/share/examples/soju \
			${DOCDIR} ${DOCDIR}/ext

SOJU_USER?=		soju
SOJU_GROUP?=		soju
PKG_GROUPS=		${SOJU_GROUP}
PKG_USERS=		${SOJU_USER}:${SOJU_GROUP}

OWN_DIRS_PERMS+=	${VARBASE}/lib/soju ${SOJU_USER} ${SOJU_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/run/soju ${SOJU_USER} ${SOJU_GROUP} 0700

PKG_SYSCONFSUBDIR=	soju
CONF_FILES=		${PREFIX}/share/examples/soju/config \
			${PKG_SYSCONFDIR}/config
# Install an empty file so that running sojudb will leave the right perms
CONF_FILES_PERMS=	/dev/null ${VARBASE}/lib/soju/main.db \
			${SOJU_USER} ${SOJU_GROUP} 0644

RCD_SCRIPTS+=		soju

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Fixing /run path in man page
SUBST_FILES.man=	doc/soju.1.scd
SUBST_SED.man=		-e 's;/run/soju/admin;${VARBASE}/run/soju/admin;g'

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/soju ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sojuctl ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/sojudb ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/migrate-db ${DESTDIR}${PREFIX}/bin/soju-migrate-db
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/migrate-logs ${DESTDIR}${PREFIX}/bin/soju-migrate-logs
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/znc-import ${DESTDIR}${PREFIX}/bin/soju-znc-import
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/casemap-logs.sh ${DESTDIR}${PREFIX}/bin/soju-casemap-logs.sh

post-install:
	scdoc < ${WRKSRC}/doc/soju.1.scd > ${WRKSRC}/doc/soju.1
	scdoc < ${WRKSRC}/doc/sojuctl.1.scd > ${WRKSRC}/doc/sojuctl.1
	${INSTALL_MAN} ${WRKSRC}/doc/soju.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/sojuctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/contrib/soju.service ${DESTDIR}${PREFIX}/share/examples/soju/soju.service
	${INSTALL_DATA} ${WRKSRC}/config.in ${DESTDIR}${PREFIX}/share/examples/soju/config
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/getting-started.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/per-user-ip.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/certbot.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/clients.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/tlstunnel.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/README.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/account-required.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/bouncer-networks.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/filehost.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/no-implicit-names.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/read.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/search.md ${DESTDIR}${DOCDIR}/ext
	${INSTALL_DATA} ${WRKSRC}/doc/ext/webpush.md ${DESTDIR}${DOCDIR}/ext

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
