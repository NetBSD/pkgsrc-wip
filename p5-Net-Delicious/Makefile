# $NetBSD: Makefile,v 1.7 2012/10/04 18:42:21 asau Exp $

DISTNAME=	Net-Delicious-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://search.cpan.org/dist/Net-Delicious/
COMMENT=	OOP for the del.icio.us API

BUILD_DEPENDS+=	p5-Test-Simple>=0.47:../../devel/p5-Test-Simple

DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-Simple>=2.08:../../textproc/p5-XML-Simple
DEPENDS+=	p5-Log-Dispatch>=2.11:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-Time-HiRes>=1.65:../../time/p5-Time-HiRes
DEPENDS+=	p5-IO-stringy>=2.10:../../devel/p5-IO-stringy
DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML
DEPENDS+=	p5-Config-Simple>=2:../../sysutils/p5-Config-Simple

PERL5_PACKLIST=	auto/Net/Delicious/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
