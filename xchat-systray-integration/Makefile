# $NetBSD: Makefile,v 1.2 2004/02/12 06:00:26 minskim Exp $

DISTNAME=	xchat-systray-integration-2.4.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchat2-plugins/}

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://blight.altervista.org/index.php?act=Systray
COMMENT=	Systray icon plugin for X-Chat

DEPENDS=	xchat>=2.0:../../chat/xchat2

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

SUBST_CLASSES+=		cflags
SUBST_MESSAGE.cflags=	"Fixing CFLAGS."
SUBST_STAGE.cflags=	post-patch
SUBST_FILES.cflags=	Makefile
SUBST_SED.cflags=	-e 's|CFLAGS = -O2 -Wall|CFLAGS = ${CFLAGS}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/systray.so ${LOCALBASE}/lib/xchat/plugins/

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
