# $NetBSD: Makefile,v 1.6 2009/04/23 11:02:32 emil_s Exp $

DISTNAME=	newsbeuter-2.0
CATEGORIES=	news
MASTER_SITES=	http://www.newsbeuter.org/downloads/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.newsbeuter.org/downloads/
COMMENT=	Open-source RSS/Atom feed reader for text terminals

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config msgfmt

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

# NetBSD iconv implementation doesn't support
# the wchar_t encoding (upon stfl relies).
.if ${OS} == "NetBSD"
.include "../../converters/libiconv/buildlink3.mk"
.endif

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/stfl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
