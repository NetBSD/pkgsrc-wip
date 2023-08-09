# $NetBSD$

DISTNAME=	auto-admin-0.7.18.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	f86a525f2885fc67c9c7aa961198aa2b4a8958cc

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

.include "../../mk/bsd.pkg.mk"
