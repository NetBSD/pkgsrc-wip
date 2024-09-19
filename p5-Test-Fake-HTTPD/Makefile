# $NetBSD: Makefile,v 1.1 2014/03/10 07:18:56 jgoamakf Exp $

DISTNAME=	Test-Fake-HTTPD-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Fake-HTTPD
COMMENT=	Fake HTTP Server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon
DEPENDS+=		p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=		p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

TEST_DEPENDS+=		p5-Test-UseAllModules-[0-9]*:../../devel/p5-Test-UseAllModules
TEST_DEPENDS+=		p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork
TEST_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Test/Fake/HTTPD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
