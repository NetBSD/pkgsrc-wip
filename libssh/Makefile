# $NetBSD: Makefile,v 1.7 2013/01/31 20:46:31 noud4 Exp $
#

DISTNAME=		libssh-0.5.4
CATEGORIES=		security
MASTER_SITES=		https://red.libssh.org/attachments/download/41/

MAINTAINER=		ndb@NetBSD.org
HOMEPAGE=		http://www.libssh.org/
COMMENT=		SSHv2 and SSHv1 protocol
LICENSE=		2-clause-bsd

DIST_SUBDIR=		security

.include "../../mk/bsd.prefs.mk"

# ftp: Unsupported URL scheme `https'
.if ${OPSYS} == "NetBSD"
FETCH_USING=		curl
.endif

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--prefix=${PREFIX}

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
