# $NetBSD: Makefile,v 1.1.1.1 2006/02/23 09:43:36 jgoamakf Exp $

DISTNAME=		Template-Provider-Encoding-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Template-Provider-Encoding/
COMMENT=		Explicitly declare encodings of your templates

DEPENDS+=		p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Template/Provider/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
