# $NetBSD: Makefile,v 1.5 2010/03/16 08:33:41 jgoamakf Exp $

DISTNAME=	URI-Find-Rule-0.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://search.cpan.org/dist/URI-Find-Rule/
COMMENT=	Simpler interface to URI::Find

DEPENDS+=	p5-URI-Find>=0:../../www/p5-URI-Find
DEPENDS+=	p5-Text-Glob>=0:../../textproc/p5-Text-Glob

PERL5_PACKLIST= auto/URI/Find/Rule/.packlist

PERL5_MODULE_TYPE= Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
