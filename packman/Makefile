# $NetBSD: Makefile,v 1.3 2007/06/22 15:50:04 koifren Exp $

DISTNAME=	packman-0.0.3
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
