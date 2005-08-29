# $NetBSD: Makefile,v 1.1.1.1 2005/08/29 17:50:01 kuli0020 Exp $

DISTNAME=	Email-Address-1.80
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-Address/
COMMENT=	RFC 2822 Address Parsing and Creation

DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/Address/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
