# $NetBSD: Makefile,v 1.2 2008/07/28 11:14:55 athaba Exp $
#

DISTNAME=		Metadata-0.24
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Metadata/}

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://search.cpan.org/dist/Metadata/
COMMENT=		Perl classes for simple metadata

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Metadata/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
