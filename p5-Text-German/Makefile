# $NetBSD: Makefile,v 1.6 2009/03/18 12:14:47 cheusov Exp $

DISTNAME=		Text-German-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/dist/Text-German/
COMMENT=		German grundform reduction

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/German/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
