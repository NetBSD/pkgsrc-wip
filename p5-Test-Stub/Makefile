# $NetBSD: Makefile,v 1.1 2014/04/05 20:02:16 jgoamakf Exp $

DISTNAME=	Test-Stub-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Stub/
COMMENT=	Simple stubbing library for Perl5
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/Stub/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
