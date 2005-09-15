# $NetBSD: Makefile,v 1.3 2005/09/15 18:24:47 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Static-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Static
COMMENT=	Serve static files with Catalyst

PERL5_REQD+=    5.8.0

DEPENDS+=	p5-Catalyst>=2.99:../../wip/p5-Catalyst
DEPENDS+=	p5-File-MimeInfo>=0.11:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp

PERL5_PACKLIST= auto/Catalyst/Plugin/Static/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
