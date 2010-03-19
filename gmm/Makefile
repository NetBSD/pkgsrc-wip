# $NetBSD: Makefile,v 1.1.1.1 2010/03/19 21:06:22 jihbed Exp $
#

DISTNAME=	gmm-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/getfem/stable/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://home.gna.org/getfem/gmm_intro.html
COMMENT=	Gmm++ is a generic C++ template library for sparse
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
