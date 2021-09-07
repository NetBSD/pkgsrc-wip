# $NetBSD$

DISTNAME=	yt-dlp-2021.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt-dlp/}
# \TODO: create symlink, as mpv makes use of youtube-dl?
# CONFLICTS=	youtube-dl-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/yt-dlp
COMMENT=	Youtube-dl fork with new features and patches
LICENSE=	unlicense

USE_LANGUAGES=	# none

# Only for >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

# optional runtime dependencies. here or in install notes?
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
DEPENDS+=	rtmpdump-[0-9]*:../../net/rtmpdump
# pycrytodome
# websockets
# keyring
# mplayer or mpv
# phantomjs
# sponskrub

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
