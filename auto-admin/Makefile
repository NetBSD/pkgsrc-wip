# $NetBSD$

DISTNAME=	auto-admin-0.7.15.21
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	685bc7293fc36e83ecdf1cfeede4d66742f26f2f

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/auto-admin
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

# auto-pkgsrc-prefix looks for pkg_add, which isn't guaranteed to be
# installed on NetBSD
DEPENDS+=	pkg_install>=0:../../pkgtools/pkg_install

USE_LANGUAGES=	# none

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix+=	-e 's|/usr/pkg|${PREFIX}|g'
SUBST_SED.prefix+=	-e 's|/usr/pkgsrc|${PKGSRCDIR}|g'
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-prefix
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-dir

.include "../../mk/bsd.pkg.mk"
