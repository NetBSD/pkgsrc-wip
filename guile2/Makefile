# $NetBSD: Makefile,v 1.10 2014/04/22 00:46:48 lexort Exp $
#

DISTNAME=	guile-2.0.11
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.gnu.org/gnu/guile/

MAINTAINER=	root@zta.lk
HOMEPAGE=	ftp://ftp.gnu.org/gnu/guile/
COMMENT=	Official extension language for the GNU operating system
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
# On NetBSD 5, -C is not recognized by /usr/bin/make
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in

CONFIGURE_ARGS+=	--without-threads
#.include "../../mk/pthread.buildlink3.mk"

# Because we don't explicitly depend on readline, disable it.
# Note that if readline is included, license becomes 'AND gnu-gplv-3'.
CONFIGURE_ARGS+=	--without-readline-prefix

# These are in the order given in guile's README.
.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
