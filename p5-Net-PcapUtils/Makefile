# $NetBSD: Makefile,v 1.4 2009/07/17 17:11:05 adrian_p Exp $
#

DISTNAME=	Net-PcapUtils-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~timpotter/Net-PcapUtils-0.01/
COMMENT=	Utility routines for Net::Pcap module

DEPENDS+=	p5-Net-Pcap>=0.3:../../net/p5-Net-Pcap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Net/PcapUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
