# $NetBSD: Makefile,v 1.2 2010/01/20 06:59:27 obache Exp $
#

DISTNAME=	ibus-table-code-1.2.0.20100120
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The code tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

# latex is in ibus-table.
CONFIGURE_ARGS+=	--disable-latex

.include "../../lang/python/application.mk"
.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
