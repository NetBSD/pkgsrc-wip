# $NetBSD: Makefile,v 1.8 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		libticalcs
PKGNAME=		libticalcs-4.4.9
CATEGORIES=		math
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Database of TI calculator model information

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
