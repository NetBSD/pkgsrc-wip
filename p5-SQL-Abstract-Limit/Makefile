# $NetBSD: Makefile,v 1.1.1.1 2006/03/10 17:46:13 kuli0020 Exp $

DISTNAME=	SQL-Abstract-Limit-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/D/DA/DAVEBAIRD/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract-Limit/
COMMENT=	SQL Portability layer for LIMIT emulation

DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-SQL-Abstract>=1.2:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0}:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/SQL/Abstract/Limit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
