# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 14:40:37 xtraeme Exp $
#

DISTNAME=		eag-2.3
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.kun.nl/pub/eag/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapboen@sci.kun.nl
HOMEPAGE=		http://www.cs.kun.nl/~kees/eag
COMMENT=		Transducer generator using affix grammars

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
