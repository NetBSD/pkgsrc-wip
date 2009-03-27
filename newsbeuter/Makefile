# $NetBSD: Makefile,v 1.3 2009/03/27 09:50:07 smoppy Exp $

DISTNAME=	newsbeuter-1.3
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

.include "../../wip/stfl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
