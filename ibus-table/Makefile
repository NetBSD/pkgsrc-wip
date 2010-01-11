# $NetBSD: Makefile,v 1.3 2010/01/11 08:56:40 obache Exp $
#

DISTNAME=	ibus-table-1.2.0.20100111
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The Table engine for IBus platform
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ibus-table.pc.in

.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
