# $NetBSD: Makefile,v 1.4 2006/07/21 04:06:03 yeled Exp $

DISTNAME=	URI-Find-Rule-0.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://search.cpan.org/dist/URI-Find-Rule/
COMMENT=	Simpler interface to URI::Find

DEPENDS+=	p5-URI-Find>=0:../../wip/p5-URI-Find
DEPENDS+=	p5-Text-Glob>=0:../../textproc/p5-Text-Glob

PERL5_PACKLIST= auto/URI/Find/Rule/.packlist

PERL5_MODULE_TYPE= Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
