# $NetBSD: Makefile,v 1.13 2010/01/17 12:03:29 thomasklausner Exp $

DISTNAME=	newsbeuter-2.0
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.newsbeuter.org/downloads/

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://www.newsbeuter.org/downloads/
COMMENT=	Open-source RSS/Atom feed reader for text terminals

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt perl
USE_NCURSES=	yes
USE_GNU_ICONV=	yes

REPLACE_PERL+=	txt2h.pl

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS}=="Linux"
# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/^ifneq.*//; s/^endif.*//'
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/stfl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
