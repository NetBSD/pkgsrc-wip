# $NetBSD: Makefile,v 1.1.1.1 2007/02/06 09:16:38 netcap Exp $

DISTNAME=	Catalyst-Devel-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Devel/
COMMENT=	Development tool kit for Catalyst

DEPENDS+=	p5-Catalyst>=5.70:../../wip/p5-Catalyst
DEPENDS+=	p5-Catalyst-Manual>=5.70:../../wip/p5-Catalyst-Manual
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Path-Class>=0.09:../../wip/p5-Path-Class
DEPENDS+=	p5-Catalyst-Action-RenderView>=0.04:../../wip/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple>=0.14:../../wip/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader>=0:../../wip/p5-Catalyst-Plugin-ConfigLoader
DEPENDS+=	p5-YAML>=0.55:../../textproc/p5-YAML
DEPENDS+=	p5-Module-Install>=0.64:../../devel/p5-Module-Install
DEPENDS+=	p5-File-Copy-Recursive>=0:../../wip/p5-File-Copy-Recursive

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Devel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
