# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:52 shattered Exp $

DISTNAME=	Set-Object-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Set-Object/
COMMENT=	Perl module to manage sets of objects

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/Set/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
