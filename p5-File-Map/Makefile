# $NetBSD: Makefile,v 1.1.1.1 2010/04/21 15:26:33 uccwen Exp $
#

DISTNAME=	File-Map-0.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/File-Map
COMMENT=	Memory mapping made simple and safe
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Readonly>=0:../../devel/p5-Readonly

PERL5_PACKLIST=		auto/File/Map/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
