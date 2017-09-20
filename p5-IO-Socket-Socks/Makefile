# $NetBSD: Makefile,v 1.4 2015/01/15 00:25:55 lexort Exp $

DISTNAME=	IO-Socket-Socks-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~oleg/IO-Socket-Socks-0.51/lib/IO/Socket/Socks.pm
COMMENT=	Create SOCKS v4/v5 client or server
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/IO/Socket/Socks/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
