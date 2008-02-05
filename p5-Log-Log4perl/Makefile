# $NetBSD: Makefile,v 1.8 2008/02/05 11:15:54 obache Exp $

DISTNAME=	Log-Log4perl-1.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5llp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://log4perl.sourceforge.net/
COMMENT=	Log4j implementation for Perl

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-PathTools>=0.82:../../devel/p5-PathTools
DEPENDS+=	p5-Test-Simple>=0.45:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Log/Log4perl/.packlist

REPLACE_PERL+=	lib/Log/Log4perl/Layout/PatternLayout/Multiline.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
