# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:50 shattered Exp $

DISTNAME=	Catalyst-View-TT-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-TT/
COMMENT=	Template Toolkit view class for Catalyst

PERL5_REQD+=	5.8.1
DEPENDS+=	p5-Catalyst>=5.50:../../wip/p5-Catalyst
DEPENDS+=	p5-Path-Class>=0:../../wip/p5-Path-Class
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Timer>=0:../../wip/p5-Template-Timer

PERL5_PACKLIST= auto/Catalyst/View/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
