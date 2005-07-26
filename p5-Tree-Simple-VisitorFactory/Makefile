# $NetBSD: Makefile,v 1.2 2005/07/26 05:58:14 jgoamakf Exp $

DISTNAME=		Tree-Simple-VisitorFactory-0.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5trs
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Tree-Simple-VisitorFactory/
COMMENT=		Collection of visitor objects for use with Tree::Simple

DEPENDS+=		p5-Test-Exception>=0.20:../../devel/p5-Test-Exception
DEPENDS+=		p5-Tree-Simple>=1.00:../../devel/p5-Tree-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Tree/Simple/VisitorFactory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
