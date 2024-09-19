# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:57 asau Exp $
#

DISTNAME=	mopac7-1.11
PKGNAME=	lib${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mopac7/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://sourceforge.net/projects/mopac7/
COMMENT=	Semi-empirical Quantum Chemistry Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c fortran77

PKGCONFIG_OVERRIDE+=	libmopac7.pc.in

.include "../../mk/bsd.pkg.mk"
