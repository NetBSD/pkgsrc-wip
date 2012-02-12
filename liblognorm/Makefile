# $NetBSD: Makefile,v 1.4 2012/02/12 19:14:07 bartoszkuzma Exp $
#

DISTNAME=	liblognorm-0.3.3
CATEGORIES=	devel
MASTER_SITES=	http://www.liblognorm.com/files/download/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.liblognorm.com/
COMMENT=	Tool to normalize log data
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lognorm.pc.in

.include "../../wip/libee/buildlink3.mk"
.include "../../wip/libestr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
