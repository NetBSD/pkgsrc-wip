# $NetBSD: Makefile,v 1.6 2006/11/10 19:07:00 plunky Exp $
#

DISTNAME=		unshield-0.5
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Extractor for InstallShield cabinet files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	CPPFLAGS=-I${WRKSRC}/lib
USE_LIBTOOL=		yes
USE_LANGUAGES=		c

pre-configure:
.if !exists(/usr/include/stdbool.h)
	cp ${FILESDIR:Q}/stdbool.h ${WRKSRC:Q}/lib
.endif

.include "../../mk/bsd.pkg.mk"
