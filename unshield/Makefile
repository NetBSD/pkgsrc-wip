# $NetBSD: Makefile,v 1.2 2004/08/17 18:32:56 tvierling Exp $
#

DISTNAME=		unshield-0.3
CATEGORIES=		archivers
MASTER_SITES=		${SOURCEFORGE_MASTER_SITES}

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Extractor for InstallShield cabinet files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		CPPFLAGS=-I${WRKSRC}/lib
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libunshield.la

pre-configure:
.if !exists(/usr/include/stdbool.h)
	${CP} ${FILESDIR}/stdbool.h ${WRKSRC}/lib
.endif

.include "../../mk/bsd.pkg.mk"
