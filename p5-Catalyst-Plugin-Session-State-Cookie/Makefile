# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 16:16:58 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NU/NUFFIN/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-Cookie/
COMMENT=	Stores a Catalyst Session in a Cookie

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.01:../../wip/p5-Catalyst-Plugin-Session

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/State/Cookie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
