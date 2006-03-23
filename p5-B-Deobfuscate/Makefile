# $NetBSD: Makefile,v 1.1.1.1 2006/03/23 18:24:23 kuli0020 Exp $

DISTNAME=	B-Deobfuscate-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/B-Deobfuscate/
COMMENT=	Extension to B::Deparse for use in de-obfuscating source code

DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML
DEPENDS+=	p5-B-Keywords>=0.03:../../wip/p5-B-Keywords

PERL5_PACKLIST=	auto/B/Deobfuscate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
