# $NetBSD: Makefile,v 1.2 2010/03/05 13:08:54 obache Exp $
#

DISTNAME=	ibus-table-latin-1.2.0.20100305
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The Latin tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

# already in ibus-table.
CONFIGURE_ARGS+=	--disable-compose

.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
