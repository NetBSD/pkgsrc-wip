# $NetBSD: Makefile,v 1.5 2004/09/23 05:59:52 jlamwww Exp $
#

DISTNAME=		libtifiles
PKGNAME=		libtifiles-0.5.6
CATEGORIES=		db
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for reading files from TI calculators

WRKSRC=			${WRKDIR}/${PKGNAME}

LDFLAGS+=		-lintl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
