# $NetBSD: Makefile,v 1.1.1.1 2012/03/14 21:51:11 bubuchka Exp $

DISTNAME=	MongoDB-0.45
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KR/KRISTINA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MongoDB/
COMMENT=	Mongo Driver for Perl

LICENSE=        apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Data-Types-[0-9]*:../../wip/p5-Data-Types
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-boolean-[0-9]*:../../devel/p5-boolean

PERL5_PACKLIST=	auto/MongoDB/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
