# $NetBSD: Makefile,v 1.6 2004/02/17 02:55:19 blef Exp $
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
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
