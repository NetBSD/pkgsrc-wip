# $NetBSD: Makefile,v 1.2 2006/01/25 11:35:36 jgoamakf Exp $

DISTNAME=	UNIVERSAL-isa-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NU/NUFFIN/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-isa/
COMMENT=	Hack around people calling UNIVERSAL::isa() as a function
PERL5_REQD+=	5.8.0

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/UNIVERSAL/isa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
