# $NetBSD: Makefile,v 1.3 2003/09/22 04:57:21 xtraeme Exp $
#

DISTNAME=	freeglut-2.0.0.rc5
PKGNAME=	${DISTNAME:S/.r/r/}
WRKSRC=         ${WRKDIR}/freeglut-2.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library

CONFLICTS=		glut-[0-9]*:../../graphics/glut

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
