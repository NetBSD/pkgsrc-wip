# $NetBSD: Makefile,v 1.7 2007/12/30 18:41:26 koifren Exp $

DISTNAME=	packman-0.0.5
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.ngnetworks.ro/

MAINTAINER=	kefren@ngnetworks.ro
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Perl wip/pkgmanager clone

USE_TOOLS+=	perl:run

USE_LANGUAGES=	# empty

do-build:
do-install:
	cp ${WRKSRC}/packman.pl ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
