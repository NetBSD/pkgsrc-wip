# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 11:08:41 obache Exp $
#

DISTNAME=	ibus-table-cantonese-1.2.0.20100107
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://codes.google.com/p/ibus/
COMMENT=	The Cantonese and derived tables for IBus-Table
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
