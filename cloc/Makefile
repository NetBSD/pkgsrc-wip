# $NetBSD: Makefile,v 1.4 2012/11/12 15:59:46 othyro Exp $
#

DISTNAME=	cloc-1.55
CATEGORIES=	devel perl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cloc/}
EXTRACT_SUFX=	.pl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cloc.sourceforge.net/
COMMENT=	Statistics utility to count lines of code 
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long
DEPENDS+=	p5-IO>=1.25:../../devel/p5-IO

WRKSRC=		${WRKDIR}

NO_BUILD= yes

REPLACE_PERL+=  ${DISTNAME}.pl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.pl ${DESTDIR}${PREFIX}/bin/cloc

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
