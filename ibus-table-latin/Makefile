# $NetBSD: Makefile,v 1.1.1.1 2010/01/15 11:43:49 obache Exp $
#

DISTNAME=	ibus-table-latin-1.2.0.20100108
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The Latin tables for IBus-Table
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

# already in ibus-table.
CONFIGURE_ARGS+=	--disable-compose

.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
