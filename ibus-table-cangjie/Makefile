# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 10:27:45 obache Exp $
#

DISTNAME=	ibus-table-cangjie-1.2.0.20100106
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://codes.google.com/p/ibus/
COMMENT=	CangJie tables for IBus-Table
LICENSE=	gnu-gpl-v3

DEPENDS+=	ibus-table>=1.2.0:../../wip/ibus-table

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../wip/ibus-table/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
