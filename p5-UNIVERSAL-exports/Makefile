# $NetBSD: Makefile,v 1.8 2012/10/04 19:12:01 asau Exp $

DISTNAME=		UNIVERSAL-exports-0.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uex
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/UNIVERSAL-exports/
COMMENT=		Lightweight, universal exporting of variables

DEPENDS+=		p5-Exporter-Lite>=0.01:../../devel/p5-Exporter-Lite
DEPENDS+=		p5-UNIVERSAL-require>=0.01:../../devel/p5-UNIVERSAL-require

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/UNIVERSAL/exports/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
