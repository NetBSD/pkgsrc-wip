# $NetBSD$

DISTNAME=	hut-0.6.0
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~xenrox/hut/refs/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~xenrox/hut
COMMENT=	CLI tool for sr.ht
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

GO_BUILD_PATTERN=	.

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-build:
	${RUN} cd ${WRKSRC} && ${MAKE} doc/hut.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/hut.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
