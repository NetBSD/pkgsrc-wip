# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:52 shattered Exp $

DISTNAME=	Test-use-ok-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Test-use-ok/
COMMENT=	Alternative to Test::More::use_ok

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Test/use/ok/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
