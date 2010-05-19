# $NetBSD: Makefile,v 1.12 2010/05/19 09:29:24 obache Exp $
#

DISTNAME=	ibus-pinyin-1.3.6
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	PinYin engine for IBus platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake intltool msgfmt

# taken from ${WRKSRC}/data/db/open-phrase/Makefile.in
DBVER=		1.2.99
DBTAR=		pinyin-database-${DBVER}.tar.bz2

post-extract:
	${RUN} cd ${WRKSRC}/data/db/open-phrase;	\
	mkdir -p db;					\
	mv ${WRKDIR}/db/main.db db/open-phrase.db;	\
	touch ${DBTAR} stamp-db

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-pinyin.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

CONFIGURE_ARGS+=	--disable-db-android
CONFIGURE_ARGS+=	--enable-db-open-phrase

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
