# $NetBSD: Makefile,v 1.1 2014/11/15 09:31:10 noud4 Exp $

DISTNAME=	CGI-Expand-2.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/B/BO/BOWMANBS/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~bowmanbs/CGI-Expand/
COMMENT=	Convert flat hash to nested data using TT2\'s dot convention

DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Exception>0:../../devel/p5-Test-Exception

USE_LANGUAGES+=	# empty
PERL5_PACKLIST=	auto/CGI/Expand/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
