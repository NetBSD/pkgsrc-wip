# $NetBSD: Makefile,v 1.2 2009/11/01 08:48:40 obache Exp $
#

DISTNAME=	ibus-anthy-1.2.0.20090917
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Japanese input engine for IBus
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-anthy-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config msgfmt gmake

.include "../../devel/swig/buildlink3.mk"
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
