# $NetBSD: Makefile,v 1.5 2004/12/17 12:56:05 hfath Exp $
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

BUILD_TARGET=	all man rash

USE_PKGINSTALL=	YES
RCD_SCRIPTS=	radmind

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
