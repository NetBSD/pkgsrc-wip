# $NetBSD$

DISTNAME=	htop-2.2.0.20200227
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fraggerfox/}
GITHUB_TAG=	37ccabf6ec2c62007b4353df01c74eb95c301825
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/fraggerfox/htop/tree/netbsd-no-procfs/netbsd
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

# This version does not need procfs mount in NetBSD
# Report bugs to fox@NetBSD.org
CONFLICTS=	htop-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf autoconf automake gmake m4 pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

REPLACE_PYTHON+=	scripts/MakeHeader.py

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -vif

.include "../../lang/python/application.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
