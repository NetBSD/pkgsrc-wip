# $NetBSD: Makefile,v 1.1 2014/11/15 11:44:48 noud4 Exp $

DISTNAME=	Data-DPath-Validator-0.093411
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NP/NPEREZ/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~nperez/Data-DPath-Validator/
COMMENT=	Validate data based on template data

DEPENDS+=	p5-MooseX-Role-BuildInstanceOf>0:../../wip/p5-MooseX-Role-BuildInstanceOf 	
DEPENDS+=	p5-Data-DPath>0:../../wip/p5-Data-DPath
DEPENDS+=	p5-Data-Visitor>0:../../devel/p5-Data-Visitor

USE_LANGUAGES+=	# empty
PERL5_PACKLIST=	auto/Data/DPath/Validator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
