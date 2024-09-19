# $NetBSD$

DISTNAME=	gitea-tea-0.7.0
CATEGORIES=	net
MASTER_SITES=	-https://gitea.com/gitea/tea/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://gitea.com/gitea/tea
COMMENT=	Official Gitea command-line client
LICENSE=	mit

WRKSRC=		${WRKDIR}/tea
USE_TOOLS+=	gmake

.include "go-modules.mk"

INSTALLATION_DIRS=	bin
EGDIR=			${PREFIX}/share/examples/gitea-tea/auto-completion

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tea ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/autocomplete.sh ${DESTDIR}${EGDIR}/gitea-tea.bash
	${INSTALL_DATA} ${WRKSRC}/contrib/autocomplete.zsh ${DESTDIR}${EGDIR}/_tea

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
