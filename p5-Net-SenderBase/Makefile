# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:21 asau Exp $
#

DISTNAME=	Net-SenderBase-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSERGEANT/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	https://metacpan.org/pod/release/MSERGEANT/Net-SenderBase-1.01/lib/Net/SenderBase.pm
COMMENT=	Query the senderbase.org service

.include "../../lang/perl5/license.mk"
LICENSE=        ${PERL5_LICENSE}

DEPENDS+=	p5-Net-DNS>=0.23:../../net/p5-Net-DNS

PERL5_PACKLIST=	auto/Net/SenderBase/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
