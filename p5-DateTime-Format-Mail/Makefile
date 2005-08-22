# $NetBSD: Makefile,v 1.1.1.1 2005/08/22 18:19:36 kuli0020 Exp $

DISTNAME=	DateTime-Format-Mail-0.2901
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Convert between DateTime and RFC2822/822 formats

DEPENDS+=       p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple
DEPENDS+=	p5-Params-Validate>=0.67:../../devel/p5-Params-Validate

BUILDING_MODULE_BUILD=  yes
PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/DateTime/Format/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
