# $NetBSD: Makefile,v 1.2 2004/03/28 07:49:58 bjan2 Exp $
#

DISTNAME=		libtifiles
PKGNAME=		libtifiles-0.5.6
CATEGORIES=		db
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for reading files from TI calculators

WRKSRC=			${WRKDIR}/${PKGNAME}

LDFLAGS+=		-lintl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
