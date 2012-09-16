# $NetBSD: Makefile,v 1.3 2012/09/16 08:56:35 jihbed Exp $
#

DISTNAME=	libxc-1.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.tddft.org/programs/octopus/down.php?file=libxc/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://www.tddft.org/programs/octopus/wiki/index.php/Libxc
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config perl
USE_LANGUAGES=	c fortran


REPLACE_PERL+=	src/get_funcs.pl


PKGCONFIG_OVERRIDE+=	build/libxc.pc.in

.include "../../mk/bsd.pkg.mk"
