# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:16 ykomatsu Exp $
#

DISTNAME=		ecl-0.9c
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ecls.sourceforge.net/index.html
COMMENT=		Embeddable Common Lisp

WRKSRC=			${WRKDIR}/${DISTNAME}-build/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../${DISTNAME}/src/configure
USE_TOOLS+=		gmake

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
