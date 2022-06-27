# $NetBSD$

DISTNAME=	v20201206-phase3
PKGNAME=	noto-ttf-20201206
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=	noto-fonts
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fonts.google.com/noto
COMMENT=	Noto fonts for all languages
LICENSE=	ofl-v1.1

DEPENDS+=	noto-emoji-ttf-[0-9]*:../../fonts/noto-emoji-ttf
DEPENDS+=	noto-sans-cjk-ttf-[0-9]*:../../wip/noto-sans-cjk-ttf
DEPENDS+=	noto-serif-cjk-ttf-[0-9]*:../../wip/noto-serif-cjk-ttf

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:S,^v,,}/hinted/ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
