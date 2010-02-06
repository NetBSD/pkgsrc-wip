# $NetBSD: Makefile,v 1.2 2010/02/06 15:27:49 athaba Exp $
#

DISTNAME=	Exporter-Tidy-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Tidy
COMMENT=	Alternative way of exporting symbols in perl
# In fact the license says:
# Pick your favourite OSI approved license :)
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=user-destdir

PERL5_PACKLIST=	auto/Exporter/Tidy/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
