# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:22:16 obache Exp $
#

DISTNAME=	scim-python-0.1.13rc1
CATEGORIES=	inputmethod python
MASTER_SITES=	http://scim-python.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/scim-python/
COMMENT=	Python wrapper for Smart Common Input Method platform
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt

CONFIGURE_ARGS+=	 --disable-english-writer
CONFIGURE_ARGS+=	 --disable-pinyin
CONFIGURE_ARGS+=	 --disable-xingma

PY_PATCHPLIST=		yes

.include "../../inputmethod/scim/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
