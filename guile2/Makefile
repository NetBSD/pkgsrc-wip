# $NetBSD: Makefile,v 1.12 2014/10/14 16:00:40 thomasklausner Exp $

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
# not until boehm-gc is threaded
CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	--disable-shared

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
