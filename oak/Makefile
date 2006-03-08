# $NetBSD: Makefile,v 1.1.1.1 2006/03/08 22:14:09 jdwhite Exp $
#

DISTNAME=		oak-1.5.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ktools.org/dist/oak/

MAINTAINER=		jdwhite@jdwhite.org
HOMEPAGE=		http://www.ktools.org/dist/oak/
COMMENT=		System log reporting tool

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=

RCD_SCRIPTS=		oak
CONF_FILES=		${PREFIX}/share/examples/oak/oak.conf ${PREFIX}/etc/oak.conf

INSTALLATION_DIRS+=	share/examples/oak

post-install:
	${INSTALL_DATA}	${FILESDIR}/oak.conf* ${PREFIX}/share/examples/oak/

.include "../../mk/bsd.pkg.mk"
