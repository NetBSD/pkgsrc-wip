# $NetBSD: Makefile,v 1.4 2004/12/17 11:00:00 hfath Exp $
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
CONFIGURE_ARGS+=	--with-radminddir=${VARBASE}/radmind
PLIST_SUBST+=		VARBASE=${VARBASE}

USE_PKGINSTALL=	YES
RCD_SCRIPTS=	radmind

post-build:
	(cd ${WRKSRC} && ${MAKE} man rash)

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
