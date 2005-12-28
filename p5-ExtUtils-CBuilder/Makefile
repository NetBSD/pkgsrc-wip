# $NetBSD: Makefile,v 1.1.1.1 2005/12/28 21:49:36 kuli0020 Exp $

DISTNAME=	ExtUtils-CBuilder-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	kuli0020@umn.edu
COMMENT=	Compile and link C code for Perl modules

BUILD_DEPENDS+=	p5-PathTools>=0:../../wip/p5-PathTools

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/ExtUtils/CBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
