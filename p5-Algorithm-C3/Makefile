# $NetBSD: Makefile,v 1.1.1.1 2006/04/07 20:00:02 kuli0020 Exp $

DISTNAME=	Algorithm-C3-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-C3/
COMMENT=	Module for merging hierarchies using the C3 algorithm

BUILD_DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Algorithm/C3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
