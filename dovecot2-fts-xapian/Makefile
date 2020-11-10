# $NetBSD$

GITHUB_PROJECT=	fts-xapian
DISTNAME=	1.4.3
PKGNAME=	dovecot2-fts-xapian-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=grosjo/}
DIST_SUBDIR=	dovecot2-fts-xapian

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/grosjo/fts-xapian
COMMENT=	FTS plugin for Dovecot
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	dovecot>=2.3.7:../../mail/dovecot2 \
		icu>=60.0:../../textproc/icu \
		xapian>=1.4.17:../../textproc/xapian

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake pkg-config

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

pre-configure:
	set -e; cd ${WRKSRC}; \
        autoreconf -i

post-install:
	${STRIP} ${DESTDIR}${PREFIX}/lib/dovecot/lib21_fts_xapian_plugin.so

.include "../../textproc/xapian/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
