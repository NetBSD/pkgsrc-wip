# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:44 othyro Exp $
#

DISTNAME=	libitl-0.7.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

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

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/prayertime/doc/method-info.txt \
		 ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
