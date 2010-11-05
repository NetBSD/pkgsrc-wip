# $NetBSD: Makefile,v 1.3 2010/11/05 04:20:26 shattered Exp $

DISTNAME=	Email-AddressParser-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-AddressParser/
COMMENT=	RFC 2822 Address Parsing and Creation

PERL5_PACKLIST= auto/Email/AddressParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
