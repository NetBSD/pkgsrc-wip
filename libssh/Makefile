# $NetBSD: Makefile,v 1.6 2013/01/31 17:39:31 noud4 Exp $
#

DISTNAME=		libssh-0.5.3
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.libssh.org/files/0.5/

MAINTAINER=		ndb@NetBSD.org
HOMEPAGE=		http://www.libssh.org/
COMMENT=		SSHv2 and SSHv1 protocol
LICENSE=		2-clause-bsd

DIST_SUBDIR=		security

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--prefix=${PREFIX}

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
