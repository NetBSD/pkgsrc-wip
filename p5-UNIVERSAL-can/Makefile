# $NetBSD: Makefile,v 1.5 2006/04/13 21:36:04 kuli0020 Exp $

DISTNAME=	UNIVERSAL-can-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-can/
COMMENT=	Hack around people calling UNIVERSAL::can() as a function
PERL5_REQD+=	5.6.0

DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Simple>=0.60:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/UNIVERSAL/can/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
