# $NetBSD: Makefile,v 1.4 2010/05/17 09:15:49 obache Exp $
#

DISTNAME=	lmtp2nntp-1.4.1
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.ossp.org/pkg/tool/lmtp2nntp/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/tool/lmtp2nntp/
COMMENT=	OSSP lmtp2nntp - Mail to News Gateway
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
# XXX: LIBS in CONFIGURE_ENV confuse subsequent configure script.
# XXX: main configure rewrite LIBS before call subsequent configure script,
# XXX: it contains unwanted variables, so will be failed to test links.
# XXX: LIBS passed with CONFIGURE_ARGS will be passed to sub configure AS-IS. 
CONFIGURE_ARGS+=	LIBS=${LIBS:M*:Q}

MAKE_JOBS_SAFE=	no

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
