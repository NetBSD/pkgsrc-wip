# $NetBSD: Makefile,v 1.3 2010/02/05 15:32:56 athaba Exp $
#

DISTNAME=	Hash-AsObject-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/Hash-AsObject
COMMENT=	Treat hashes as objects, with arbitrary accessors/mutators
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=user-destdir

PERL5_PACKLIST=	auto/Hash/AsObject/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
