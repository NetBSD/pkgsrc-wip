# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 21:42:47 tomasbodzar Exp $
#

DISTNAME=	LWP-Protocol-socks-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~scr/LWP-Protocol-socks-1.5/lib/LWP/Protocol/socks4.pm
COMMENT=	adds support for SOCKS to p5-libwww
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=	p5-IO-Socket-SSL*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-Socket-Socks*:../../wip/p5-IO-Socket-Socks

.include "../../devel/lwp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
