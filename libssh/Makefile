# $NetBSD: Makefile,v 1.5 2013/01/31 14:59:28 noud4 Exp $
#XDG-wip-1.1.2nb2 gtk-grdc-0.4.0nb2

DISTNAME=		libssh-0.5.3
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
#CONFIGURE_ARGS+=	-Wno-dev

PKGCONFIG_OVERRIDE+=	libssh.pc.in
TEST_TARGET=		check

pre-configure:
	#${RM} ${WRKSRC}/CMakeCache.txt
	cd ${WRKSRC} && cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} -Wno-dev
	#${CD} ${WRKSRC} && cmake -Wno-dev

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
