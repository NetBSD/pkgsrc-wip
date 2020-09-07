# $NetBSD: Makefile,v 1.1 2013/04/13 08:39:13 jgoamakf Exp $

DISTNAME=	PerlIO-Layers-0.012
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Querying your filehandle's capabilities
HOMEPAGE=	https://metacpan.org/release/PerlIO-Layers
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/PerlIO/Layers/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
