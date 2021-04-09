# $NetBSD$

DISTNAME=	htop-3.0.5.20210409
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fraggerfox/}
GITHUB_PROJECT=	htop-dev
GITHUB_TAG=	2fa45e8107d49c69e9925b7eba6912e40210a8e0
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
