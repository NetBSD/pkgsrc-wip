# $NetBSD: Makefile,v 1.4 2004/09/23 05:59:51 jlamwww Exp $
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
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
