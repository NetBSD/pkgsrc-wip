# $NetBSD: Makefile,v 1.1.1.1 2005/08/29 19:58:09 kuli0020 Exp $

DISTNAME=	Email-Send-1.46
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-Send/
COMMENT=	Email::Send - Simply Sending Email

DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	p5-Return-Value>=1.28:../../devel/p5-Return-Value

PERL5_PACKLIST= auto/Email/Send/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
