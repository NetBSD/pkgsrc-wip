# $NetBSD: Makefile,v 1.1.1.1 2008/09/05 13:52:38 pettai Exp $
#

PKGNAME=	p5-${DISTNAME}
DISTNAME=	Net-validMX-2.2.0
CATEGORIES=	perl5 mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://search.cpan.org/~kmcgrail/Net-validMX-2.2.0/lib/Net/validMX.pm
COMMENT=	Use DNS and/or regular expressions to verify a email address

DEPENDS+=	p5-Net-DNS>=0.53:../../net/p5-Net-DNS

PERL5_PACKLIST=	auto/Net/validMX/.packlist
# url2pkg-marker (please do not remove this line.)

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
