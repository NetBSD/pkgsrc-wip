# $NetBSD: Makefile,v 1.10 2015/03/21 16:57:16 schmonz Exp $

DISTNAME=		Text-VimColor-0.28
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-VimColor/
COMMENT=		Syntax color text in HTML or XML using Vim
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
BUILD_DEPENDS+=		p5-Test-File-ShareDir-[0-9]*:../../devel/p5-Test-File-ShareDir

DEPENDS+=		p5-Path-Class>=0.02:../../devel/p5-Path-Class
DEPENDS+=		p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
#DEPENDS+=		p5-Term-ANSIColor>=3:../../devel/p5-Term-ANSIColor
DEPENDS+=		vim{,-gtk,gtk2,-kde,-motif,-xaw}-[0-9]*:../../editors/vim

PERL5_PACKLIST=		auto/Text/VimColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
