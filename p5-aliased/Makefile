# $NetBSD: Makefile,v 1.1.1.1 2008/08/08 10:52:45 athaba Exp $
#

DISTNAME=	aliased-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/O/OV/OVID/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/aliased/
COMMENT=	Use shorter versions of class name

PKG_DESTDIR_SUPPORT=user-destdir

BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/aliased/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
