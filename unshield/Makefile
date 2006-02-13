# $NetBSD: Makefile,v 1.5 2006/02/13 20:38:54 plunky Exp $
#

DISTNAME=		unshield-0.3
CATEGORIES=		archivers
MASTER_SITES=		${SOURCEFORGE_MASTER_SITES}

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Extractor for InstallShield cabinet files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	CPPFLAGS=-I${WRKSRC:Q}/lib
USE_LIBTOOL=		yes

pre-configure:
.if !exists(/usr/include/stdbool.h)
	${CP} ${FILESDIR:Q}/stdbool.h ${WRKSRC:Q}/lib
.endif

.include "../../mk/bsd.pkg.mk"
