# $NetBSD$

DISTNAME=       oggfwd
PKGNAME=        oggfwd-20150329
CATEGORIES=     multimedia
GIT_REPO=       https://r-w-x.org/r/oggfwd.git

MAINTAINER=     jake.slazenger@yandex.com
HOMEPAGE=       http://v2v.cc/~j/oggfwd/
COMMENT=        pipes an ogg stream to an icecast server.
LICENSE=        gnu-gpl-v2

USE_LANGUAGES=  c

# url2pkg-marker (please do not remove this line.)
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
