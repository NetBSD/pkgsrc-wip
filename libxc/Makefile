# $NetBSD: Makefile,v 1.1.1.1 2009/12/05 21:06:58 jihbed Exp $
#

DISTNAME=	libxc-1.0-alpha
PKGNAME=	libxc-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tddft.org/programs/octopus/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.tddft.org/programs/octopus/wiki/index.php/Libxc
COMMENT=	Libxc is the ETSF library of exchange-correlation functionals
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_LANGUAGES=	c fortran

REPLACE_PERL+=	src/get_funcs.pl
CONFIGURE_ARGS+=	--disable-fortran

.include "../../mk/bsd.pkg.mk"
