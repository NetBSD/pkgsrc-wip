# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 18:04:43 daprice Exp $
#

DISTNAME=		socket++-1.12.10
CATEGORIES=		wip
MASTER_SITES=		http://www.hstraub.at/linux/downloads/src/socket++-1.12.10/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://ftp2.at.freebsd.org/pub/FreeBSD/distfiles/
COMMENT=		C++ class library for UNIX Sockets with exception handling

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_BUILDLINK3=		YES

USE_LIBTOOL=		YES
AUTOMAKE_REQD=          1.4
AUTOCONF_REQD=          2.50
GNU_CONFIGURE=          YES
USE_GNU_TOOLS+=		make

pre-configure:
		cd ${WRKSRC};						\
		${LOCALBASE}/bin/libtoolize --automake;                 \
		${ACLOCAL} -I .;                                        \
		${AUTOHEADER};                                          \
		${AUTOMAKE} --add-missing;                              \
		${AUTOCONF};                                            \

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
