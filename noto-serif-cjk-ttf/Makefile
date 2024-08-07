# $NetBSD$

DISTNAME=	05_NotoSerifCJKOTF
PKGNAME=	noto-serif-cjk-ttf-${GITHUB_RELEASE:S,^Serif,,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=	noto-cjk
GITHUB_RELEASE=	Serif2.003
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}-${GITHUB_RELEASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fonts.google.com/noto
COMMENT=	Noto Serif CJK fonts
LICENSE=	ofl-v1.1

CONFLICTS+=	noto-cjk-[0-9]*

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
