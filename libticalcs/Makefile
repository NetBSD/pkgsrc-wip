# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 07:55:51 bjan2 Exp $
#

DISTNAME=		libticalcs
PKGNAME=		libticalcs-4.4.9
CATEGORIES=		math
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Database of TI calculator model information

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
