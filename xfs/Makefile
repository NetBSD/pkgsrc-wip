# $NetBSD: Makefile,v 1.4 2014/08/22 09:14:38 thomasklausner Exp $

DISTNAME=		xfs-1.1.4
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg version of X font server

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

RCD_SCRIPTS=		xfs

# The same as X11R7
# CONF_FILES=		share/examples/fs/config etc/X11/fs/config
# INSTALL_DIRS+=		share/examples/fs
# AUTO_MKDIRS=		yes

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXfont+=	libXfont>=1.4.5
.include "../../x11/libXfont/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# # Upstream does not supply sample.config as a sample, so copy it.
# post-build:
# 	${MKDIR} -p         		${WRKSRC}/share/examples/fs
# 	${CP} ${WRKSRC}/config/config	${WRKSRC}/share/examples/fs/config
#
# post-install:
# 	${INSTALL_DATA} ${WRKSRC}/share/examples/fs/config \
# 			${PREFIX}/share/examples/fs/config
