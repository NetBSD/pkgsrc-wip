# $NetBSD: Makefile,v 1.4 2012/09/16 15:31:31 jihbed Exp $
#

DISTNAME=	libxc-1.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.tddft.org/programs/octopus/down.php?file=libxc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.tddft.org/programs/octopus/wiki/index.php/Libxc
COMMENT=	Libxc is the ETSF library of exchange-correlation functionals
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config perl
USE_LANGUAGES=	c fortran


REPLACE_PERL+=	src/get_funcs.pl


PKGCONFIG_OVERRIDE+=	build/libxc.pc.in

.include "../../mk/bsd.pkg.mk"
