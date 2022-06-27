# $NetBSD$

DISTNAME=	morisawa-biz-ud-mincho-fonts
PKGNAME=	biz-ud-mincho-ttf-${GITHUB_RELEASE:S,^v,,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=	morisawa-biz-ud-mincho
GITHUB_RELEASE=	v1.05
DIST_SUBDIR=	${GITHUB_PROJECT}-${GITHUB_RELEASE}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googlefonts/morisawa-biz-ud-mincho/
COMMENT=	Morisawa BIZ UDMincho font
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/fonts/ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
