# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-1.5.7
PKGNAME=	dovecot2-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=grosjo/}
GITHUB_PROJECT=	fts-xapian
GITHUB_TAG=	${PKGVERSION_NOREV}

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

.include "../../textproc/xapian/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
