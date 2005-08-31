# $NetBSD: Makefile,v 1.1.1.1 2005/08/31 16:18:47 kuli0020 Exp $

DISTNAME=	Catalyst-View-TT-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-TT
COMMENT=	Template Toolkit view class for Catalyst

PERL5_REQD+=    5.8.0
DEPENDS+=	p5-Catalyst>=5.00:../../www/p5-Catalyst
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Timer>=0:../../www/p5-Template-Timer

PERL5_PACKLIST= auto/Catalyst/View/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
