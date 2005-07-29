# $NetBSD: Makefile,v 1.1.1.1 2005/07/29 14:28:37 kuli0020 Exp $

DISTNAME=	Date-Range-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Date-Range/
COMMENT=	Date::Range - deal with a range of dates

BUILD_DEPENDS=  p5-Date-Simple>=0.03:../../time/p5-Date-Simple
DEPENDS+=       p5-Test-Simple>=0.54:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Date/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
