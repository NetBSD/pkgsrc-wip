# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:29 thomasklausner Exp $
#

DISTNAME=	Net-PcapUtils-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~timpotter/Net-PcapUtils-0.01/
COMMENT=	Utility routines for Net::Pcap module

DEPENDS+=	p5-Net-Pcap>=0.3:../../net/p5-Net-Pcap


PERL5_PACKLIST=	auto/Net/PcapUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
