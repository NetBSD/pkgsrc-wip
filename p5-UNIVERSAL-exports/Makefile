# $NetBSD: Makefile,v 1.7 2009/03/18 11:51:25 cheusov Exp $

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
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/UNIVERSAL/exports/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
