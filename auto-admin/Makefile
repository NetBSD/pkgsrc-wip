# $NetBSD$

DISTNAME=	auto-admin-0.8.3.11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	6e70f0d97c60dd9470cec2e4aefe880b3e7f0ed3

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/auto-admin
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix+=	-e 's|/usr/pkg|${PREFIX}|g'
SUBST_SED.prefix+=	-e 's|/usr/pkgsrc|${PKGSRCDIR}|g'
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-prefix
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-dir

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
