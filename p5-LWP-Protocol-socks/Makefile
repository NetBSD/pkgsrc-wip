# $NetBSD: Makefile,v 1.3 2012/11/13 22:25:40 othyro Exp $

DISTNAME=	LWP-Protocol-socks-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~scr/LWP-Protocol-socks-1.5/lib/LWP/Protocol/socks4.pm
COMMENT=	Adds support for SOCKS to p5-libwww
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-Socket-Socks-[0-9]*:../../wip/p5-IO-Socket-Socks

.include "../../devel/lwp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
