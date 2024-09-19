# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Net-IP-Match-Regexp-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CD/CDOLAN/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	https://metacpan.org/pod/Net::IP::Match::Regexp
COMMENT=	Efficiently match IP addresses against ranges

.include "../../lang/perl5/license.mk"
LICENSE=        ${PERL5_LICENSE}

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/IP/Match/Regexp/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
