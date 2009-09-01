# $NetBSD: Makefile,v 1.1.1.1 2009/09/01 13:12:01 udontknow Exp $
#

DISTNAME=	Net-Syslog-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LH/LHOWARD/}

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/L/LH/LHOWARD/
COMMENT=	Extension for sending syslog messages directly to a remote syslogd

.include "../../lang/perl5/license.mk"
LICENSE=        ${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/Syslog/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
