# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Model-CDBI-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}
PERL5_REQD+=	5.6.0

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-CDBI/
COMMENT=	CDBI model class for Catalyst

DEPENDS+=	p5-Class-DBI-Loader>=0.2:../../wip/p5-Class-DBI-Loader
DEPENDS+=	p5-Catalyst-Runtime>=4:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-DBI>=0:../../databases/p5-Class-DBI


PERL5_PACKLIST= auto/Catalyst/Model/CDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
