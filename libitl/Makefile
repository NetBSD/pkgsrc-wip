# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=	libitl-0.7.0
CATEGORIES=	time
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/ITL%20Library%20%28libitl%29/libitl-0.7.0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=ITL
COMMENT=	The Islamic Tools Libraries of calculation time and measurement
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-* FreeBSD-*-* OpenBSD-*-*

INSTALL_MAKE_FLAGS+=	includedir=${DESTDIR}${PREFIX}/include/itl \
			libdir=${DESTDIR}${PREFIX}/lib/itl

DOCDIR=	${PREFIX}/share/doc/libitl

INSTALLATION_DIRS=  ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/prayertime/doc/method-info.txt \
		 ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
