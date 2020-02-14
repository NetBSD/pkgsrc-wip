# $NetBSD$

GITHUB_PROJECT=	zodiac
GITHUB_TAG=	v0.2.5
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nuex/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/nuex/zodiac/
COMMENT=	Static website generator written in awk and sh
LICENSE=	mit

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		config.mk Makefile
#SUBST_SED.fix-paths+=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,$${PREFIX},${DESTDIR}${PREFIX},g'

WRKSRC=		${WRKDIR}/zodiac-0.2.5

.include "../../mk/bsd.pkg.mk"
