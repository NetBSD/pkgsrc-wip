# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 01:28:35 mpasternak Exp $
#

DISTNAME=		ecl-0.9c
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ecls.sourceforge.net/index.html
COMMENT=		Embeddable Common Lisp

WRKSRC=			${WRKDIR}/${DISTNAME}-build/

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../${DISTNAME}/src/configure
USE_GNU_TOOLS+=		make

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
