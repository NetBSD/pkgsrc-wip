# $NetBSD: Makefile,v 1.1.1.1 2011/04/14 09:07:40 bartoszkuzma Exp $
#

DISTNAME=		libestr-0.1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://libestr.adiscon.com/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://libestr.aniscon.com/
COMMENT=		Library for some string essentials
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libestr.pc.in

.include "../../mk/bsd.pkg.mk"
