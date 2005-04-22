# $NetBSD: Makefile,v 1.1.1.1 2005/04/22 02:25:55 jgoamakf Exp $

DISTNAME=		Tree-Simple-1.14
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5trs
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Tree-Simple/
COMMENT=		Simple tree object for Perl

DEPENDS+=		p5-Test-Exception>=0.20:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
