# $NetBSD$

DISTNAME=	lci-${GITHUB_TAG}
PKGNAME=	lci-${GITHUB_TAG:S/v//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=justinmeza/}
GITHUB_TAG=	v0.11.2

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	A LOLCODE interpreter written in C
HOMEPAGE=	http://lolcode.org/
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
