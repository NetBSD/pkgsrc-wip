# $NetBSD: Makefile,v 1.4 2010/01/03 06:30:15 obache Exp $
#

DISTNAME=	ibus-hangul-1.2.0.20100102
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.googlecode.com/p/ibus/
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-hangl-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt intltool

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.10
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
