# $NetBSD: Makefile,v 1.1.1.1 2006/04/07 18:49:04 kuli0020 Exp $

DISTNAME=	Data-Visitor-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Data-Visitor/
COMMENT=	Visitor style traversal of Perl data structures

BUILD_DEPENDS+= {perl>=5.7.1,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-use-ok>=0:../../wip/p5-Test-use-ok
BUILD_DEPENDS+=	p5-Test-MockObject>=1.04:../../wip/p5-Test-MockObject
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Data/Visitor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
