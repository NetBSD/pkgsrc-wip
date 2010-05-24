# $NetBSD: Makefile,v 1.2 2010/05/24 14:11:52 asau Exp $
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
USE_LANGUAGES=	c fortran

PKGCONFIG_OVERRIDE+=	libmopac7.pc.in

.include "../../mk/bsd.pkg.mk"
