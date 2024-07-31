# $NetBSD$

DISTNAME=	soju-${VERSION}
VERSION=	0.8.1
CATEGORIES=	chat
MASTER_SITES=	https://codeberg.org/emersion/soju/releases/download/v${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://soju.im/
COMMENT=	User friendly IRC bouncer
LICENSE=	gnu-agpl-v3

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Fixing /run path in man page
SUBST_FILES.man=	doc/soju.1.scd
SUBST_SED.man=		-e 's;/run/soju/admin;${VARBASE}/run/soju.sock;g'

TOOL_DEPENDS+=	scdoc>=0:../../textproc/scdoc

BUILD_DEFS+=	VARBASE

GO_BUILD_PATTERN+=	-ldflags ' \
			-X codeberg.org/emersion/soju/config.DefaultPath=${PKG_SYSCONFDIR}/config \
			-X codeberg.org/emersion/soju/config.DefaultUnixAdminPath=${VARBASE}/run/soju.sock'
GO_BUILD_PATTERN+=	./cmd/soju ./cmd/sojuctl ./cmd/sojudb \
			./contrib/migrate-db ./contrib/migrate-logs \
			./contrib/znc-import

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PREFIX}/share/examples/soju

PKG_SYSCONFSUBDIR=	soju
CONF_FILES=		${PREFIX}/share/examples/soju/config \
			${PKG_SYSCONFDIR}/config

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
	${INSTALL_MAN} ${WRKSRC}/doc/soju.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/sojuctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/contrib/soju.service ${DESTDIR}${PREFIX}/share/examples/soju/soju.service
	${INSTALL_DATA} ${WRKSRC}/config.in ${DESTDIR}${PREFIX}/share/examples/soju/config

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
