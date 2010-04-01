# $NetBSD: Makefile,v 1.1.1.1 2010/04/01 08:23:34 shindenmorr Exp $
#

DISTNAME=	squidview-0.76
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://www.rillion.net/squidview/
COMMENT=	program which monitors and displays squid logs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
