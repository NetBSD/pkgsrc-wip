# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 07:40:16 bjan2 Exp $
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
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_GNU_TOOLS+=		make

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
