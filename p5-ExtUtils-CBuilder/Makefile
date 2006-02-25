# $NetBSD: Makefile,v 1.2 2006/02/25 00:33:04 minskim Exp $

DISTNAME=	ExtUtils-CBuilder-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	kuli0020@umn.edu
COMMENT=	Compile and link C code for Perl modules

BUILD_DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/ExtUtils/CBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
