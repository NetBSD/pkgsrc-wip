# $NetBSD: Makefile,v 1.4 2012/10/04 19:12:00 asau Exp $

DISTNAME=		Text-VimColor-0.14
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tvc
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-VimColor/
COMMENT=		Syntax color text in HTML or XML using Vim
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-ShareDir-Install-[0-9]*:../../wip/p5-File-ShareDir-Install

DEPENDS+=		p5-Path-Class>=0.02:../../devel/p5-Path-Class
DEPENDS+=		p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=		p5-Term-ANSIColor>=3:../../devel/p5-Term-ANSIColor
DEPENDS+=		vim{,-gtk,gtk2,-kde,-motif,-xaw}-[0-9]*:../../editors/vim

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/VimColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
