# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 12:11:47 hfath Exp $
#

DISTNAME=	radmind-1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://rsug.itd.umich.edu/software/radmind/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://rsug.itd.umich.edu/software/radmind/
COMMENT=	Remote file administration and integrity tool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

post-build:
	(cd ${WRKSRC} && ${MAKE} man rash)

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
