# $NetBSD: Makefile,v 1.1 2014/11/15 10:31:04 noud4 Exp $

DISTNAME=	Data-DPath-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SC/SCHWIGON/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~schwigon/Data-DPath/
COMMENT=	DPath is not XPath!

DEPENDS+=	p5-Scalar-List-Utils>0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Sub-Exporter>0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-aliased>0:../../devel/p5-aliased
DEPENDS+=	p5-Text-Balanced>0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Test-Deep>0:../../devel/p5-Test-Deep
DEPENDS+=	p5-List-MoreUtils>0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Safe>0:../../wip/p5-Safe
DEPENDS+=	p5-Class-XSAccessor>0:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Iterator-Util>0:../../wip/p5-Iterator-Util
DEPENDS+=	p5-Data-Dumper>0:../../wip/p5-Data-Dumper

USE_LANGUAGES+=	# empty
PERL5_PACKLIST= auto/Data/DPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
