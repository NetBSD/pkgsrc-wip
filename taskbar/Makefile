# $NetBSD: Makefile,v 1.1.1.1 2004/05/22 04:56:06 jeremy-c-reed Exp $
#

DISTNAME=		taskbar-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=taskbar/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://taskbar.sourceforge.net/
COMMENT=		Panel for X11 for menu and to show windows

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/taskbar
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/taskbar/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/taskbar
	${INSTALL_DATA} ${WRKSRC}/doc/example_.taskbar \
		${PREFIX}/share/examples/taskbar/

.include "../../graphics/imlib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
