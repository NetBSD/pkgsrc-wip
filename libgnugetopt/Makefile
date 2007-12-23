# $NetBSD: Makefile,v 1.1.1.1 2007/12/23 01:33:08 netcap Exp $
#

DISTNAME=	libgnugetopt-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	GNU getopt library

NO_CONFIGURE=	yes
USE_LIBTOOL=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include/gnugetopt.h
	${INSTALL_DATA} ${WRKSRC}/libgnugetopt.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libgnugetopt.so.1 ${PREFIX}/lib
	cd ${PREFIX}/lib && ln -sf libgnugetopt.so.1 libgnugetopt.so

.include "../../mk/bsd.pkg.mk"
