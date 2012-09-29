# $NetBSD: Makefile,v 1.3 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	guile-2.0.5
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.gnu.org/gnu/guile/

MAINTAINER=	a@zta.lk
HOMEPAGE=	ftp://ftp.gnu.org/gnu/guile/
COMMENT=	The official extension language for the GNU operating system.
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/libunistring/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
