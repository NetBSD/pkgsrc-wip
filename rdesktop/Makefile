# $NetBSD: Makefile,v 1.1.1.1 2003/11/15 05:33:56 grantbeattie Exp $
#

DISTNAME=		rdesktop-1.3.0
CATEGORIES=		net
WRKSRC=			${WRKDIR}/rdesktop
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK2=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

LDFLAGS+=		${LIBOSSAUDIO}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
