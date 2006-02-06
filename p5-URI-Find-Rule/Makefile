# $NetBSD: Makefile,v 1.3 2006/02/06 18:06:06 thomasklausner Exp $

DISTNAME=	URI-Find-Rule-0.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://search.cpan.org/dist/URI-Find-Rule/
COMMENT=	Simpler interface to URI::Find

#DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-URI-Find>=0:../../wip/p5-URI-Find
DEPENDS+=	p5-Text-Glob>=2.08:../../textproc/p5-Text-Glob
#DEPENDS+=	p5-Log-Dispatch>=2.11:../../devel/p5-Log-Dispatch
#DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
#DEPENDS+=	p5-Time-HiRes>=1.65:../../time/p5-Time-HiRes
#DEPENDS+=	p5-IO-stringy>=2.10:../../devel/p5-IO-stringy
#DEPENDS+=	p5-File-Spec>=0.80:../../devel/p5-File-Spec
#DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

PERL5_PACKLIST= auto/URI/Find/Rule/.packlist

PERL5_MODULE_TYPE= Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
