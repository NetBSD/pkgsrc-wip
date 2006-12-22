# $NetBSD: Makefile,v 1.1.1.1 2006/12/22 08:48:35 jgoamakf Exp $

DISTNAME=		Text-VimColor-0.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tvc
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-VimColor/
COMMENT=		Syntax color text in HTML or XML using Vim

DEPENDS+=		p5-Path-Class>=0.02:../../wip/p5-Path-Class
DEPENDS+=		vim{,-gtk,gtk2,-kde,-motif,-xaw}-[0-9]*:../../editors/vim

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/VimColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
