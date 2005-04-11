# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:41 tvierling Exp $
#

DISTNAME=	Net-PcapUtils-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~timpotter/Net-PcapUtils-0.01/
COMMENT=	Utility routines for Net::Pcap module

DEPENDS+=	p5-Net-Pcap>=0.3:../../net/p5-Net-Pcap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/PcapUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
