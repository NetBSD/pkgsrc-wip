# $NetBSD: Makefile,v 1.4 2003/10/07 16:33:03 xtraeme Exp $
#

DISTNAME=	freeglut-2.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library

CONFLICTS=	glut-[0-9]*:../../graphics/glut

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
