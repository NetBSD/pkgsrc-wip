# $NetBSD: Makefile,v 1.1.1.1 2006/03/10 18:41:37 kuli0020 Exp $

DISTNAME=	Module-Find-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Module-Find/
COMMENT=	Lets you find and use modules in categories

DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/Module/Find/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
