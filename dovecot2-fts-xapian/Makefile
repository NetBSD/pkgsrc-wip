# $NetBSD$

DISTNAME=		${GITHUB_PROJECT}-1.7.1
PKGNAME=		dovecot2-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=grosjo/}
GITHUB_PROJECT=		fts-xapian
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		otis@NetBSD.org
HOMEPAGE=		https://github.com/grosjo/fts-xapian
COMMENT=		FTS plugin for Dovecot
LICENSE=		gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake pkg-config

WRKSRC=			${WRKDIR}/${DISTNAME}

pre-configure:
	set -e; cd ${WRKSRC}; \
        autoreconf -i

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
