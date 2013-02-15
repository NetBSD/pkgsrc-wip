# $NetBSD: Makefile,v 1.9 2013/02/15 17:10:42 noud4 Exp $
#

DISTNAME=		libssh-0.5.4
CATEGORIES=		security
MASTER_SITES=		https://red.libssh.org/attachments/download/41/

MAINTAINER=		noud4@home.nl
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
