# $NetBSD: Makefile,v 1.1.1.1 2005/08/31 14:59:39 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-SubRequest-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-SubRequest/
COMMENT=	Serve static files from config->{root}.
PERL5_REQD+=    5.8.0

DEPENDS+=	p5-Catalyst>=2.99:../../www/p5-Catalyst

PERL5_PACKLIST= auto/Catalyst/Plugin/SubRequest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
