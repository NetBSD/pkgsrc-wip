# $NetBSD: Makefile,v 1.1 2006/11/29 14:44:12 cheusov Exp $
#

DISTNAME=		AppConfig-Std-1.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		lang misc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.cpan.org/modules/by-module/AppConfig/
COMMENT=		AppConfig::Std Perl module

PKG_INSTALLATION_TYPES= overwrite pkgviews
PERL5_PACKLIST=		auto/AppConfig/Std/.packlist

DEPENDS+=		p5-AppConfig-[0-9]*:../../devel/p5-AppConfig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
