# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	tscrape-0.1
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/tscrape/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/tscrape/file/README.html
COMMENT=	Twitter scraper
LICENSE=	isc

GIT_REPOSITORIES=	tscrape
GIT_REPO.tscrape=	git://git.codemadness.org/tscrape
WRKSRC=			${WRKDIR}/tscrape

USE_LANGUAGES=	c99

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
