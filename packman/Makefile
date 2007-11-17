# $NetBSD: Makefile,v 1.5 2007/11/17 19:41:21 koifren Exp $

DISTNAME=	packman-0.0.4
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.netbsd.ro/

MAINTAINER=	kefren@ngnetworks.ro
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Perl wip/pkgmanager clone

WRKSRC=		work

USE_TOOLS+=	perl:run

USE_LANGUAGES=	# empty

do-build:
do-install:
	cp ${WRKDIR}/packman.pl ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
