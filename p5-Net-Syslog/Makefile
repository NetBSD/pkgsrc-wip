# $NetBSD: Makefile,v 1.2 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Net-Syslog-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LH/LHOWARD/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/L/LH/LHOWARD/
COMMENT=	Extension for sending syslog messages directly to a remote syslogd
LICENSE=        ${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/Syslog/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
