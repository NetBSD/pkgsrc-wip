# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 17:47:45 kuli0020 Exp $

DISTNAME=	Sub-Override-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Sub-Override/
COMMENT=	Perl extension for easily overriding subroutines

DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
DEPENDS+=	p5-Sub-Uplevel>=0:../../devel/p5-Sub-Uplevel
BUILD_DEPENDS+= {perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/Sub/Override/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
