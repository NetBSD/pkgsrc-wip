# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:55 asau Exp $
#

DISTNAME=	mixnet-1.1.2-p1
PKGNAME=	mixnet-1.1.2
CATEGORIES=	biology
MASTER_SITES=	http://stat.genopole.cnrs.fr/_media/logiciels/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://stat.genopole.cnrs.fr/logiciels/mixnet
COMMENT=	Erdos-Renyi Mixture for Networks
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c c++ fortran77

PKGCONFIG_OVERRIDE+=	tclap-1.2.0/tclap.pc.in

.include "../../mk/bsd.pkg.mk"
