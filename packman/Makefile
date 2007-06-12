# $NetBSD: Makefile,v 1.1 2007/06/12 13:35:09 koifren Exp $

DISTNAME=	packman-0.0.1
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.netbsd.ro/

MAINTAINER=	kefren@netbsd.ro
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Perl wip/pkgmanager clone

WRKSRC=		work

USE_TOOLS+=	perl:run

USE_LANGUAGES=	# empty

do-build:
do-install:
	cp ${WRKDIR}/packman.pl ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
