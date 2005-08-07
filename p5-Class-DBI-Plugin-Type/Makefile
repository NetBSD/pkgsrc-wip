# $NetBSD: Makefile,v 1.1.1.1 2005/08/07 19:33:30 jgoamakf Exp $
#

DISTNAME=	Class-DBI-Plugin-Type-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdp
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Plugin-Type/
COMMENT=	Determine type information for columns

DEPENDS+=	p5-Class-DBI>=0.95:../../databases/p5-Class-DBI
DEPENDS+=	p5-DBIx-ContextualFetch>=1.01:../../databases/p5-DBIx-ContextualFetch

PERL5_PACKLIST=	auto/Class/DBI/Plugin/Type/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
