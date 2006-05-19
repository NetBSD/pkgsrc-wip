# $NetBSD: Makefile,v 1.9 2006/05/19 16:51:18 ykomatsu Exp $
#

DISTNAME=	gxmms2-0.6.0
CATEGORIES=	audio
MASTER_SITES=	http://wejp.homelinux.org/wejp/xmms2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wejp.homelinux.org/wejp/xmms2/
COMMENT=	Graphical GTK+2-based XMMS2 client

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

BUILD_TARGET=		gxmms2

INSTALLATION_DIRS=	bin

.include "../../wip/xmms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-I${BUILDLINK_PREFIX.xmms2}/include/xmms2

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gxmms2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gxmms2

.include "../../mk/bsd.pkg.mk"
