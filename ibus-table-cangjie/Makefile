# $NetBSD: Makefile,v 1.4 2010/03/05 13:17:45 obache Exp $
#

DISTNAME=	ibus-table-cangjie-1.2.0.20100305
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://codes.google.com/p/ibus/
COMMENT=	CangJie tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	#
USE_TOOLS+=	pkg-config

.include "../../wip/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
