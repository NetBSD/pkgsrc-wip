# $NetBSD: Makefile,v 1.1 2014/03/10 07:18:56 jgoamakf Exp $

DISTNAME=	Test-Fake-HTTPD-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Fake-HTTPD/
COMMENT=	Fake HTTP Server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon
DEPENDS+=		p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=		p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=		p5-Test-UseAllModules-[0-9]*:../../devel/p5-Test-UseAllModules
BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Test/Fake/HTTPD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
