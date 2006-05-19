# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:24 ykomatsu Exp $
#

DISTNAME=		libtifiles
PKGNAME=		libtifiles-0.5.6
CATEGORIES=		db
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for reading files from TI calculators

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

LDFLAGS+=		-lintl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
