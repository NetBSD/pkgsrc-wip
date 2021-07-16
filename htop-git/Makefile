# $NetBSD$

DISTNAME=	htop-3.0.5.20210716
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=htop-dev/}
GITHUB_PROJECT=	htop
GITHUB_TAG=	c9abd788b17ab28424961310b7e224498510780c
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/fraggerfox/htop/tree/netbsd-no-procfs/netbsd
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

# This version does not need procfs mount in NetBSD
# Report bugs to fox@NetBSD.org
CONFLICTS=	htop-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf automake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./autogen.sh

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
