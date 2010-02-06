# $NetBSD: Makefile,v 1.3 2010/02/06 17:04:50 athaba Exp $
#

DISTNAME=		Metadata-0.24
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Metadata/}

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://search.cpan.org/dist/Metadata/
COMMENT=		Perl classes for simple metadata
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Metadata/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
