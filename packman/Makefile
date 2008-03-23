# $NetBSD: Makefile,v 1.9 2008/03/23 21:36:46 koifren Exp $

DISTNAME=	packman-0.0.7
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.ngnetworks.ro/

MAINTAINER=	kefren@ngnetworks.ro
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Perl wip/pkgmanager clone

USE_TOOLS+=	perl:run

DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

USE_LANGUAGES=	# empty

do-build:
do-install:
	cp ${WRKSRC}/packman.pl ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
