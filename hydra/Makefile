# $NetBSD: Makefile,v 1.3 2003/11/14 17:15:16 adrian_p Exp $
#

DISTNAME=	hydra-2.4
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.thc.org/
COMMENT=	Login password cracker

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-extract:
	@${CHMOD} 0755 ${WRKSRC}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
