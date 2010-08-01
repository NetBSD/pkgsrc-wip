# $NetBSD: Makefile,v 1.2 2010/08/01 14:57:10 asau Exp $
#

DISTNAME=	vidrioclock-0.1.20070718.0
CATEGORIES=	x11
MASTER_SITES=	http://vidrio.euler.es/vidriolib/bin/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivaniclixx@gmail.com
HOMEPAGE=	http://vidrio.euler.es/vidriolib/bin/
COMMENT=	Vidrioclock is a simple X11 clock that uses vidriolib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77

.include "../../wip/vidriolib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
