# $NetBSD: Makefile,v 1.3 2006/04/13 21:01:57 kuli0020 Exp $

DISTNAME=	UNIVERSAL-isa-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-isa/
COMMENT=	Hack around people calling UNIVERSAL::isa() as a function
PERL5_REQD+=	5.6.0

DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/UNIVERSAL/isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
