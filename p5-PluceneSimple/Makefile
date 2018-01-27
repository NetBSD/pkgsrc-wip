# $NetBSD: Makefile,v 1.8 2012/10/04 19:11:58 asau Exp $

DISTNAME=	PluceneSimple-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/ST/STRYTOAST/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/PluceneSimple/
COMMENT=	Perl interface to Plucene

DEPENDS+=	p5-PathTools>=1.2:../../devel/p5-PathTools
DEPENDS+=	p5-Plucene>=1.09:../../wip/p5-Plucene
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Time-Piece-Range>=1.0:../../wip/p5-Time-Piece-Range
BUILD_DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule
BUILD_DEPENDS+=	p5-File-Slurp>=2002.1031:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Test-Class>=0.03:../../devel/p5-Test-Class


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/PluceneSimple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
