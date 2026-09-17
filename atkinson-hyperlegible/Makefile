# $NetBSD$

DISTNAME=	atkinson-hyperlegible
PKGNAME=	${DISTNAME}-0.0.20210429
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=	atkinson-hyperlegible
# This Github project does not have tags or releases, so using the latest commit.
# Commit 1cb3116 is from 2021-04-29
GITHUB_TAG=	1cb311624b2ddf88e9e37873999d165a8cd28b46

MAINTAINER=	tallirishllama@gmail.com
HOMEPAGE=	https://github.com/googlefonts/atkinson-hyperlegible/
COMMENT=	Font with greater legibility and readability for low vision readers
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
