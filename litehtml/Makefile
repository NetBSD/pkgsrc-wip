# $NetBSD$

DISTNAME=	litehtml-0.5.0.20211003
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=litehtml/}
GITHUB_TAG=	294780d910607850e91f3a066561bbbce03d1aaf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.litehtml.com/
COMMENT=	Fast and lightweight HTML/CSS rendering engine
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DEXTERNAL_GUMBO=ON

TOOL_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share

.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
