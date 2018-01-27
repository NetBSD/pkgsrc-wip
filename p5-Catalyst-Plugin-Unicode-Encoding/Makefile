# $NetBSD: Makefile,v 1.7 2015/07/12 18:57:34 thomasklausner Exp $

DISTNAME=	Catalyst-Plugin-Unicode-Encoding-0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Unicode-Encoding/
COMMENT=	Unicode aware Catalyst
PERL5_REQD+=	5.8.1

DEPENDS+=	p5-Catalyst-Runtime>=5.2:../../www/p5-Catalyst-Runtime
#DEPENDS+=	{perl>=5.8.6,p5-Encode>=2.1}:../../textproc/p5-Encode


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Catalyst/Plugin/Unicode/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
