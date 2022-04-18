# $NetBSD$

DISTNAME=	v0.4.0
PKGNAME=	soju-${DISTNAME:S/^v//g}
CATEGORIES=	chat
MASTER_SITES=	https://git.sr.ht/~emersion/soju/archive/

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://sr.ht/~emersion/soju/
COMMENT=	User friendly IRC bouncer
LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/soju-${DISTNAME}

GO_BUILD_PATTERN=	./cmd/soju ./cmd/sojuctl

TOOL_DEPENDS+=	scdoc>=0:../../textproc/scdoc

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-install:
	scdoc < ${WRKSRC}/doc/soju.1.scd > ${WRKSRC}/doc/soju.1
	${INSTALL_DATA} ${WRKSRC}/doc/soju.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
