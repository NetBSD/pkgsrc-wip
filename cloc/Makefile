# $NetBSD: Makefile,v 1.7 2013/01/29 11:16:34 jihbed Exp $
#

DISTNAME=	cloc-1.56
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cloc/}
EXTRACT_SUFX=	.pl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cloc.sourceforge.net/
COMMENT=	Statistics utility to count lines of code
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Algorithm-Diff>=1.1902:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long
DEPENDS+=	p5-File-Path>=2.08:../../devel/p5-File-Path
DEPENDS+=	p5-File-Temp>=0.22:../../devel/p5-File-Temp
DEPENDS+=	p5-IO>=1.25:../../devel/p5-IO
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common

WRKSRC=		${WRKDIR}

NO_BUILD= yes

USE_LANGUAGES=	# none

REPLACE_PERL+=  ${DISTNAME}.pl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.pl ${DESTDIR}${PREFIX}/bin/cloc

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
