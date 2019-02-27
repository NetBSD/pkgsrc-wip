# $NetBSD$

DISTNAME=	bdfresize-1.5
CATEGORIES=	sysutils
MASTER_SITES=	https://www.distfiles.pl/

MAINTAINER=	fred@statdns.com
COMMENT=	Tool for resizing BDF format fonts
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

post-configure:
	# Do not build embedded getopt
	sed -i 's|"getopt.h"|<getopt.h>|' ${WRKSRC}/bdfresize.c
	sed -i 's|charresize.o getopt.o|charresize.o|' ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
