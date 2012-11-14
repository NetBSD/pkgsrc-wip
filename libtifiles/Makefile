# $NetBSD: Makefile,v 1.10 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=		libtifiles
PKGNAME=		libtifiles-0.5.6
CATEGORIES=		databases
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for reading files from TI calculators

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

LDFLAGS+=		-lintl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
