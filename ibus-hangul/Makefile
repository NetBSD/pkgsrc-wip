# $NetBSD: Makefile,v 1.1.1.1 2009/08/30 08:32:14 obache Exp $
#

DISTNAME=	ibus-hangul-1.1.0.20090328
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.googlecode.com/p/ibus/
COMMENT=	Korean input engine for IBus
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-hangl-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt

.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
