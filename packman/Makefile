# $NetBSD: Makefile,v 1.8 2008/03/22 14:02:17 koifren Exp $

DISTNAME=	packman-0.0.6
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
