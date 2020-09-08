# $NetBSD$

DISTNAME=	PlRPC-0.2020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MN/MNOONING/PlRPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Bundle::PlRPC
COMMENT=	All that's needed to run PlRPC-Server and Client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-Daemon-[0-9]*:../../net/p5-Net-Daemon

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[0-9.]+//}

PERL5_PACKLIST=	auto/RPC/PlServer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
