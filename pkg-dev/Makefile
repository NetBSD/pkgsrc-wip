# $NetBSD$

DISTNAME=	pkg-dev-0.3.0.26
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	6f27fa17e84553b500c1cd4801f221d3a999228b

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
