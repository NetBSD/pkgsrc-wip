# $NetBSD: Makefile,v 1.15 2012/10/04 19:44:06 asau Exp $

DISTNAME=	packman-0.0.10
CATEGORIES=	pkgtools
MASTER_SITES=	http://kefren.ngnetworks.ro/

MAINTAINER=	mihai.chelaru@ngnetworks.ro
HOMEPAGE=	http://kefren.ngnetworks.ro/
COMMENT=	Small package manager

USE_TOOLS+=	perl:run

DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

USE_LANGUAGES=	# empty
REPLACE_PERL+=	packman.pl

INSTALLATION_DIRS+=	bin

do-build:
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/packman.pl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
