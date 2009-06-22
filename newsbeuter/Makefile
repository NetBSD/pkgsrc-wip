# $NetBSD: Makefile,v 1.9 2009/06/22 15:03:49 smoppy Exp $

DISTNAME=	newsbeuter-2.0
CATEGORIES=	news
MASTER_SITES=	http://www.newsbeuter.org/downloads/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.newsbeuter.org/downloads/
COMMENT=	Open-source RSS/Atom feed reader for text terminals

PKG_DESTDIR_SUPPORT=	user-destdir

USE_NCURSES=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt perl

REPLACE_PERL+=	txt2h.pl

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

# NetBSD iconv implementation doesn't support
# the wchar_t encoding (upon stfl relies).
.if ${OPSYS} == "NetBSD"
.include "../../converters/libiconv/buildlink3.mk"
.endif

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/stfl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
