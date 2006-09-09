# $NetBSD: Makefile,v 1.1.1.1 2006/09/09 11:35:02 adrian_p Exp $
#

DISTNAME=		libdaemon-0.10
CATEGORIES=		devel
MASTER_SITES=		http://0pointer.de/lennart/projects/libdaemon/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://0pointer.de/lennart/projects/libdaemon/
COMMENT=		C library that eases the writing of UNIX daemons

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdaemon.pc.in
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-lynx

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libdaemon
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/libdaemon

.include "../../mk/bsd.pkg.mk"
