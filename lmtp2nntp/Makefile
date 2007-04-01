# $NetBSD: Makefile,v 1.2 2007/04/01 02:19:12 obache Exp $
#

DISTNAME=	lmtp2nntp-1.4.1
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.ossp.org/pkg/tool/lmtp2nntp/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/tool/lmtp2nntp/
COMMENT=	OSSP lmtp2nntp - Mail to News Gateway

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
