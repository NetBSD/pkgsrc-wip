# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:21 asau Exp $

DISTNAME=	B-Deobfuscate-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	https://metacpan.org/release/B-Deobfuscate
COMMENT=	Extension to B::Deparse for use in de-obfuscating source code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML
DEPENDS+=	p5-B-Keywords>=0.03:../../devel/p5-B-Keywords

PERL5_PACKLIST=	auto/B/Deobfuscate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
