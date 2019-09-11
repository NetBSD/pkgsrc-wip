# $NetBSD$

GITHUB_PROJECT=	youtube-dl
DISTNAME=	2019.09.01
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ytdl-org/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://ytdl-org.github.io/youtube-dl/
COMMENT=	Command-line program to download videos from YouTube
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/youtube-dl-2019.09.01
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
