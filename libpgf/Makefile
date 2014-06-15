# $NetBSD: Makefile,v 1.1 2014/06/15 10:25:39 nros Exp $

DISTNAME=	libpgf-src-6.14.12
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpgf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpgf.org/
COMMENT=	Progressive Graphics File (PGF) library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/libpgf
GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

pre-configure:
	${RUN} cp files/configure.ac ${WRKSRC}
	${RUN} cd ${WRKSRC} && ./autogen.sh

PKGCONFIG_OVERRIDE+=	libpgf.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
