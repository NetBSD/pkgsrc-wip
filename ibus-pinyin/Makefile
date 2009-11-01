# $NetBSD: Makefile,v 1.2 2009/11/01 08:48:40 obache Exp $
#

DISTNAME=	ibus-pinyin-1.2.0.20090915
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	PinYin engine for IBus
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py[0-9]*-ibus-pinyin-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config gmake msgfmt

# taken from ${WRKSRC}/engine/Makefile.in
DBVER=		0.1.10.6
DBTAR=		pinyin-database-${DBVER}.tar.bz2

post-extract:
	mv ${WRKDIR}/py.db ${WRKSRC}/engine
	touch -r ${WRKSRC}/engine/py.db ${WRKSRC}/engine/${DBTAR}

.include "../../wip/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
