# $NetBSD: Makefile,v 1.8 2014/04/04 17:40:26 realzhtw Exp $
#

DISTNAME=	guile-2.0.9
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.gnu.org/gnu/guile/

MAINTAINER=	root@zta.lk
HOMEPAGE=	ftp://ftp.gnu.org/gnu/guile/
COMMENT=	Official extension language for the GNU operating system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in

CONFIGURE_ARGS+=	--with-threads=no
#.include "../../mk/pthread.buildlink3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
