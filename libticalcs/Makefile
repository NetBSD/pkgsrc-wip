# $NetBSD: Makefile,v 1.3 2004/08/17 18:30:10 tvierling Exp $
#

DISTNAME=		libticalcs
PKGNAME=		libticalcs-4.4.9
CATEGORIES=		math
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Database of TI calculator model information

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/libticalcs-4.la
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
