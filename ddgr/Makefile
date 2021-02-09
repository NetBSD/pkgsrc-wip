# $NetBSD$

DISTNAME=	ddgr-1.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jarun/ddgr
COMMENT=	DuckDuckGo from the terminal
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	Makefile
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
