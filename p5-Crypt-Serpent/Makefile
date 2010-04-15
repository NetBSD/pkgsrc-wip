# $NetBSD: Makefile,v 1.2 2010/04/15 07:10:06 athaba Exp $
#

DISTNAME=		Crypt-Serpent-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Serpent
COMMENT=		Serpent block cipher encryption module for perl
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Crypt/Serpent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
