# $NetBSD: Makefile,v 1.1.1.1 2012/02/14 10:15:13 fhajny Exp $
#

DISTNAME=	gearmand-0.28
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/91215774/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://gearman.org/
COMMENT=	Gearman C Server and Library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "options.mk"

PKGCONFIG_OVERRIDE+=	support/gearmand.pc.in

LIBS.SunOS+=	-ldladm

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
