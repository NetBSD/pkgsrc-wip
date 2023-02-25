# $NetBSD$

DISTNAME=	pkg-dev-0.3.0.22
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	0a2b3fda923ba66b0cd5d16e9b76c574ee3776c5

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/pkg-dev
COMMENT=	Scripts to automate common tasks in pkgsrc development
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS=	pkglint>0:../../pkgtools/pkglint
DEPENDS+=	pkgdiff>0:../../pkgtools/pkgdiff
DEPENDS+=	createbuildlink>0:../../pkgtools/createbuildlink
DEPENDS+=	auto-admin>0:../../wip/auto-admin

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
