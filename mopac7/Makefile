# $NetBSD: Makefile,v 1.3 2010/08/01 14:57:09 asau Exp $
#

DISTNAME=	mopac7-1.11
PKGNAME=	lib${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=mopac7/)

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/mopac7/
COMMENT=	Semi-empirical Quantum Chemistry Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c fortran77

PKGCONFIG_OVERRIDE+=	libmopac7.pc.in

.include "../../mk/bsd.pkg.mk"
