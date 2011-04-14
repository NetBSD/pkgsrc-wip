# $NetBSD: Makefile,v 1.1.1.1 2011/04/14 09:06:55 bartoszkuzma Exp $
#

DISTNAME=		libee-0.3.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.libee.org/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.libee.org/
COMMENT=		Event Expression Library inspired by CEE
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libee.pc.in

.include "../../wip/libestr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
