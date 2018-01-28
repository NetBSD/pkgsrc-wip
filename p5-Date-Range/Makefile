# $NetBSD: Makefile,v 1.9 2015/07/12 18:57:34 thomasklausner Exp $

DISTNAME=	Date-Range-1.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Date-Range/
COMMENT=	Date::Range - deal with a range of dates
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-Date-Simple>=0.03:../../devel/p5-Date-Simple
#BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.4}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Date/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
