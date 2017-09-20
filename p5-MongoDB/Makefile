# $NetBSD: Makefile,v 1.3 2012/10/04 18:42:21 asau Exp $

DISTNAME=	MongoDB-v1.8.0
PKGNAME=	p5-${DISTNAME:S/-v/-/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONGODB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MongoDB/
COMMENT=	Mongo Driver for Perl
LICENSE=        apache-2.0

DEPENDS+=	p5-Any-Moose>=0.18:../../devel/p5-Any-Moose
DEPENDS+=	p5-Class-Method-Modifiers>=1.07:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Data-Types>=0.09:../../wip/p5-Data-Types
DEPENDS+=	p5-DateTime>=0.6600nb1:../../time/p5-DateTime
DEPENDS+=	p5-File-Slurp>=9999.19:../../devel/p5-File-Slurp
DEPENDS+=	p5-JSON>=2.53:../../converters/p5-JSON
DEPENDS+=	p5-Tie-IxHash>=1.22nb2:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Try-Tiny>=0.09:../../devel/p5-Try-Tiny
DEPENDS+=	p5-boolean>=0.28:../../devel/p5-boolean
DEPENDS+=	p5-Config-AutoConf-[0-9]*:../../devel/p5-Config-AutoConf
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny

MAKE_JOBS_SAFE=	no
PERL5_PACKLIST=	auto/MongoDB/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
