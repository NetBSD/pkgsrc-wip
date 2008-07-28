# $NetBSD: Makefile,v 1.1.1.1 2008/07/28 10:58:57 athaba Exp $
#

DISTNAME=		Crypt-Serpent-1.01
PKGNAME=		p5-${DISTNAME}
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Serpent
COMMENT=		Serpent block cipher encryption module for perl

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Crypt/Serpent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
