# $NetBSD: Makefile,v 1.7 2007/03/03 05:32:07 netcap Exp $

DISTNAME=	Log-Log4perl-1.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5llp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://log4perl.sourceforge.net/
COMMENT=	Log4j implementation for Perl

DEPENDS+=	p5-PathTools>=0.82:../../devel/p5-PathTools
DEPENDS+=	p5-Test-Simple>=0.45:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Log/Log4perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
