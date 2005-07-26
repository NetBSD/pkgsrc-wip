# $NetBSD: Makefile,v 1.3 2005/07/26 05:58:14 jgoamakf Exp $

DISTNAME=		UNIVERSAL-exports-0.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uex
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/UNIVERSAL-exports/
COMMENT=		Lightweight, universal exporting of variables

DEPENDS+=		p5-Exporter-Lite>=0.01:../../wip/p5-Exporter-Lite

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/UNIVERSAL/exports/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
