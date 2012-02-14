# $NetBSD: Makefile,v 1.1 2012/02/14 17:08:31 realzhtw Exp $
#

DISTNAME=	guile-2.0.5
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.gnu.org/gnu/guile/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	ftp://ftp.gnu.org/gnu/guile/
COMMENT=	The official extension language for the GNU operating system.
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/libunistring/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
