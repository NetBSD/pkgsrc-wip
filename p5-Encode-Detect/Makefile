# $NetBSD: Makefile,v 1.1.1.1 2006/12/26 02:17:24 jgoamakf Exp $

DISTNAME=	Encode-Detect-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Encode-Detect/
COMMENT=	Encoding that detects encoding from data

DEPENDS+=	p5-ExtUtils-CBuilder>=0.18:../../devel/p5-ExtUtils-CBuilder

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Encode/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
