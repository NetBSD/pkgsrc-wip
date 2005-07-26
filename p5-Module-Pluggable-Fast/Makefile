# $NetBSD: Makefile,v 1.3 2005/07/26 05:58:13 jgoamakf Exp $

DISTNAME=	Module-Pluggable-Fast-0.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mpf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable-Fast/
COMMENT=	Fast plugins with instantiation

DEPENDS+=	p5-UNIVERSAL-exports>=0.03:../../wip/p5-UNIVERSAL-exports
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Module/Pluggable/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
