# $NetBSD: Makefile,v 1.1.1.1 2004/06/11 19:06:45 plunky Exp $
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

pre-configure:
.if !exists(/usr/include/stdbool.h)
	${CP} ${FILESDIR}/stdbool.h ${WRKSRC}/lib
.endif

.include "../../mk/bsd.pkg.mk"
