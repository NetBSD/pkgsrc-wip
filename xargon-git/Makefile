# $NetBSD$

DISTNAME=	xargon-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Malvineous/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Malvineous/xargon/
COMMENT=	SDL port of the DOS game Xargon
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	xargon
GIT_REPO.xargon=	git://github.com/Malvineous/xargon.git
WRKSRC=			${WRKDIR}/xargon

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake pkg-config

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/SDL/buildlink3.mk"
.include "../../wip/libgamemusic/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
