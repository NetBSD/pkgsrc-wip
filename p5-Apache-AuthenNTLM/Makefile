# $NetBSD: Makefile,v 1.7 2015/02/19 13:16:15 thomasklausner Exp $

DISTNAME=	Apache-AuthenNTLM-2.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/author/SPEEVES
COMMENT=	Perl5/Apache module for NTLM authorization

PERL5_PACKLIST=	auto/Apache/AuthenNTLM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
