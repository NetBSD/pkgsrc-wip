# $NetBSD: Makefile,v 1.12 2009/03/08 08:46:29 koifren Exp $

DISTNAME=	packman-0.0.9
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.ngnetworks.ro/

MAINTAINER=	mihai.chelaru@ngnetworks.ro
HOMEPAGE=	http://kefren.ngnetworks.ro/
COMMENT=	Small package manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run

DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

USE_LANGUAGES=	# empty
REPLACE_PERL+=	packman.pl

do-build:
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/packman.pl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
