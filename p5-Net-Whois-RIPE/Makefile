# $NetBSD: Makefile,v 1.5 2015/07/12 19:01:21 thomasklausner Exp $

DISTNAME=	Net-Whois-RIPE-2.006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
HOMEPAGE=	http://www.ripe.net/
COMMENT=	Implementation of RIPE Whois

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Iterator-[0-9]*:../../wip/p5-Iterator

MAKE_PARAMS=		--online-tests
PERL5_PACKLIST=		auto/Net/Whois/RIPE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
