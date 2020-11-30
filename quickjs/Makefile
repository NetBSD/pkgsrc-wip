# $NetBSD$
#

DISTNAME=	quickjs-2020-11-08
CATEGORIES=	lang
MASTER_SITES=	https://bellard.org/quickjs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bellard.org/quickjs/
COMMENT=	Small and embeddable Javascript engine
LICENSE=	mit

USE_TOOLS=	gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjust hardcoded paths
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS+=	bin lib/quickjs include/quickjs

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
