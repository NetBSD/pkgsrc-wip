# $NetBSD: Makefile,v 1.2 2011/12/28 21:45:18 jihbed Exp $
#

DISTNAME=	cloc-1.55
CATEGORIES=	devel perl
MASTER_SITES=	http://switch.dl.sourceforge.net/project/cloc/cloc/v1.55/
EXTRACT_SUFX=	.pl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cloc.sourceforge.net/
COMMENT=	Statistics utility to count lines of code 
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long
DEPENDS+=	p5-IO>=1.25:../../devel/p5-IO

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

NO_BUILD= yes

REPLACE_PERL+=  ${DISTNAME}.pl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.pl ${DESTDIR}${PREFIX}/bin/cloc

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
