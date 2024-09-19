# $NetBSD: Makefile,v 1.00 2015/12/03 01:40:00 coypu Exp $

VER=		0_pre20160305
DISTNAME=	pangoterm-0.${VER}
CATEGORIES=	x11
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

HOMEPAGE=	http://www.leonerd.org.uk/code/pangoterm/
COMMENT=	GTK/Pango-based terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/pangoterm-0
USE_LANGUAGES=	c
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk".
.include "../../wip/libvterm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
