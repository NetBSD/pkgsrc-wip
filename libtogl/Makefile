# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:45 othyro Exp $
#

DISTNAME=	Togl2.0-src
PKGNAME=	libtogl-2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=togl/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://togl.sourceforge.net/index.html#intro
COMMENT=	Tk OpenGL widget

WRKSRC=		${WRKDIR}/Togl2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

INSTALLATION_DIRS=	share/doc/libtogl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${PREFIX}/share/doc/libtogl

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
