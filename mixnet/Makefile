# $NetBSD: Makefile,v 1.2 2011/01/24 09:07:10 jihbed Exp $
#

DISTNAME=	mixnet-1.1.2-p1
PKGNAME=	mixnet-1.1.2
CATEGORIES=	biology
MASTER_SITES=	http://stat.genopole.cnrs.fr/_media/logiciels/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://stat.genopole.cnrs.fr/logiciels/mixnet
COMMENT=	Erdos-Renyi Mixture for Networks
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c c++ fortran77

PKGCONFIG_OVERRIDE+=	tclap-1.2.0/tclap.pc.in

.include "../../mk/bsd.pkg.mk"
