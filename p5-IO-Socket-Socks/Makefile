# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 21:02:35 tomasbodzar Exp $
#

DISTNAME=	IO-Socket-Socks-0.51
PKGNAME=	p5-${DISTNAME}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~oleg/IO-Socket-Socks-0.51/lib/IO/Socket/Socks.pm
COMMENT=	create SOCKS v4/v5 client or server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
PERL5_PACKLIST=	auto/IO/Socket/Socks/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
