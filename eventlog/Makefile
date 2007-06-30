# $NetBSD: Makefile,v 1.1.1.1 2007/06/30 10:57:22 ondratu Exp $
#

DISTNAME=	eventlog-0.2.5
CATEGORIES=	net devel
MASTER_SITES=	http://www.balabit.com/downloads/files/eventlog/0.2/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.balabit.com/products/syslog-ng/
COMMENT=	New API to format and send structured log messages

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	eventlog.pc.in

.include "../../mk/bsd.pkg.mk"
