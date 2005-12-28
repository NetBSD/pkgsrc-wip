# $NetBSD: Makefile,v 1.2 2005/12/28 22:13:18 kuli0020 Exp $

DISTNAME=	ExtUtils-ParseXS-2.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	kuli0020@umn.edu
COMMENT=	Converts Perl XS code into C code
PERL5_REQD+=    5.6.0

DEPENDS+=	p5-ExtUtils-CBuilder>=0.00:../../wip/p5-ExtUtils-CBuilder

PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/ExtUtils/ParseXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
