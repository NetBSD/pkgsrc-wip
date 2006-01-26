# $NetBSD: Makefile,v 1.2 2006/01/26 10:51:25 jgoamakf Exp $

DISTNAME=		Petal-2.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ptl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPOSTLE/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Petal/
COMMENT=		Perl Template Attribute Language

DEPENDS+=		p5-MKDoc-XML>=0.75:../../wip/p5-MKDoc-XML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Petal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
