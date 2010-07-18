# $NetBSD: Makefile,v 1.2 2010/07/18 09:15:46 cheusov Exp $
#

DISTNAME=	eventlog-0.2.5
CATEGORIES=	net devel
MASTER_SITES=	http://www.balabit.com/downloads/files/eventlog/0.2/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.balabit.com/products/syslog-ng/
COMMENT=	New API to format and send structured log messages

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	eventlog.pc.in

.include "../../mk/bsd.pkg.mk"
