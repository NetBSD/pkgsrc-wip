# $NetBSD: Makefile,v 1.2 2005/08/05 18:49:44 kuli0020 Exp $

DISTNAME=	PluceneSimple-1.04
PKGNAME=	p5-Plucene-Simple-1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/ST/STRYTOAST/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/PluceneSimple/
COMMENT=	Plucene::Simple - An interface to Plucene

DEPENDS=	p5-Time-Piece-Range>=1.0:../../time/p5-Time-Piece-Range
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Plucene>=1.09:../../textproc/p5-Plucene
DEPENDS+=	p5-PathTools>=1.2:../../devel/p5-PathTools
DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule
# DEPENDS+=	p5-File-Path>=1.05:../../devel/p5-File-Path
DEPENDS+=	p5-File-Slurp>=2002.1031:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Test-Class>=0:../../devel/p5-Test-Class
#BUILD_DEPENDS+=	p5-Test-Harness>=2.30:../../devel/p5-Test-Harness

BUILDING_MODULE_BUILD=  yes
PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST= auto/Plucene/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
