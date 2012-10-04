# $NetBSD: Makefile,v 1.3 2012/10/04 18:42:22 asau Exp $

DISTNAME=	Net-Whois-RIPE-1.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
HOMEPAGE=	http://www.ripe.net/
COMMENT=	Implementation of RIPE Whois

BUILD_DEPENDS+=		{p5-Test-Simple>=0.44,perl{,-thread}>=5.8.0}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_REQD+=		5.6.0
PERL_CONFIGURE=	yes
MAKE_PARAMS=		--online-tests
PERL5_PACKLIST=		auto/Net/Whois/RIPE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
