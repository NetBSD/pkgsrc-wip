# $NetBSD: Makefile,v 1.4 2012/07/02 13:37:55 moubctez Exp $
#

DISTNAME=	gearmand-0.33
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/104788829/

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
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
