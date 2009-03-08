# $NetBSD: Makefile,v 1.2 2009/03/08 12:04:53 pettai Exp $
#

DISTNAME=	Net-validMX-2.2.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://search.cpan.org/~kmcgrail/Net-validMX-2.2.0/lib/Net/validMX.pm
COMMENT=	Use DNS and/or regular expressions to verify a email address

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-DNS>=0.53:../../net/p5-Net-DNS

PERL5_PACKLIST=	auto/Net/validMX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
