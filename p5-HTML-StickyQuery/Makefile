# $NetBSD: Makefile,v 1.2 2004/01/27 14:12:07 jgoamakf Exp $
#

DISTNAME=		HTML-StickyQuery-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sqy
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/search?dist=HTML-StickyQuery
COMMENT=		Add sticky QUERY_STRING to a tag href attributes

DEPENDS+=		p5-HTML-Parser>=3.34:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI>=1.27:../../www/p5-URI

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/StickyQuery/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
