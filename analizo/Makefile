# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 20:24:44 jihbed Exp $
#

DISTNAME=	analizo_1.16.0
PKGNAME=	analizo-1.16.0
CATEGORIES=	devel
MASTER_SITES=	http://analizo.org/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://analizo.org/
COMMENT=	Extensible source code analysis and visualization toolkit
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Test-Class>=0.36:../../devel/p5-Test-Class
DEPENDS+=	p5-Test-Exception>=0.29:../../devel/p5-Test-Exception
DEPENDS+=	p5-Graph>=0.94:../../devel/p5-Graph
DEPENDS+=	p5-Statistics-Descriptive>=3.0200:../../math/p5-Statistics-Descriptive
DEPENDS+=	p5-List-Compare>=0.37:../../textproc/p5-List-Compare
DEPENDS+=	p5-YAML>=0.72:../../textproc/p5-YAML

WRKSRC=		${WRKDIR}/analizo

#PERL5_PACKLIST=	auto/analizo_1.16.0/
USE_TOOLS+= perl
USE_LANGUAGES=	c c++

REPLACE_PERL+=	Makefile.PL analizo lib/Analizo/scripts/analizo-metrics 	\
				lib/Analizo/scripts/analizo-graph

REPLACE_RUBY=	lib/Analizo/scripts/analizo-metrics-history 			\
				lib/Analizo/scripts/analizo-evolution-matrix


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
