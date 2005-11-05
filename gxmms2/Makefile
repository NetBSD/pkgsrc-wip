# $NetBSD: Makefile,v 1.3 2005/11/05 10:34:21 leonardschmidt Exp $
#

DISTNAME=	gxmms2-0.5.1
CATEGORIES=	audio
MASTER_SITES=	http://wejp.homelinux.org/wejp/xmms2/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wejp.homelinux.org/wejp/xmms2/
COMMENT=	Graphical GTK+2-based XMMS2 client

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
BUILD_TARGET=		gxmms2

SUBST_CLASSES+=		var
SUBST_STAGE.var=	post-patch
SUBST_FILES.var=	Makefile
SUBST_SED.var=		-e 's,%%BUILDLINK_DIR%%,${BUILDLINK_DIR}/include,g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gxmms2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gxmms2

.include "../../wip/xmms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
