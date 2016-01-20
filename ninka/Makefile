# $NetBSD: Makefile,v 1.4 2013/03/04 21:58:38 thomasklausner Exp $
#

DISTNAME=	ninka-1.3
CATEGORIES=	devel
MASTER_SITES=	http://ninka.turingmachine.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ninka.turingmachine.org/
COMMENT=	License identification tool for Source Code
LICENSE=	gnu-agpl-v3

DEPENDS+=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long

USE_TOOLS+=	pax perl
NO_BUILD=	yes
USE_LANGUAGES=	# none

REPLACE_PERL+=	ninka.pl splitter/splitter.pl 											\
					extComments/hashComments.pl extComments/extComments.pl \
					senttok/senttok.pl matcher/matcher.pl filter/filter.pl

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,extComments/extComments.pl,extComments.pl,g'
SUBST_SED.paths+=	-e 's,splitter/splitter.pl,splitter.pl,g'
SUBST_SED.paths+=	-e 's,filter/filter.pl,filter.pl,g'
SUBST_SED.paths+=	-e 's,senttok/senttok.pl,senttok.pl,g'
SUBST_SED.paths+=	-e 's,matcher/matcher.pl,matcher.pl,g'
SUBST_FILES.paths+=	ninka.pl
SUBST_MESSAGE.paths=	Fixing header search paths.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ninka.pl ${DESTDIR}${PREFIX}/bin/ninka.pl
	${INSTALL_SCRIPT} ${WRKSRC}/extComments/extComments.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/splitter/splitter.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/filter/filter.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/senttok/senttok.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/matcher/matcher.pl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
