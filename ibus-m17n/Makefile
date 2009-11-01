# $NetBSD: Makefile,v 1.2 2009/11/01 08:48:40 obache Exp $
#

DISTNAME=	ibus-m17n-1.2.0.20090930
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	M17N engine for IBus
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-m17n-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
