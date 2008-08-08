# $NetBSD: Makefile,v 1.1.1.1 2008/08/08 09:37:35 athaba Exp $
#

DISTNAME=	Exporter-Tidy-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Tidy
COMMENT=	alternative way of exporting symbols

PKG_DESTDIR_SUPPORT=user-destdir

PERL5_PACKLIST=	auto/Exporter/Tidy/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
