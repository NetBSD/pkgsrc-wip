# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 21:14:35 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Pluggable-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Pluggable/
COMMENT=	Plugin for pluggable Catalyst applications

DEPENDS+=	p5-Catalyst>=5.50:../../wip/p5-Catalyst

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Plugin/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
