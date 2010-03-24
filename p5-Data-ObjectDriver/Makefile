# $NetBSD: Makefile,v 1.2 2010/03/24 05:02:08 jgoamakf Exp $

DISTNAME=	Data-ObjectDriver-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Data-ObjectDriver/
COMMENT=	Simple and generic abstraction to databases
LICENSE=	artistic-2.0

DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.08:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Trigger>=0.14:../../devel/p5-Class-Trigger
DEPENDS+=	p5-Text-SimpleTable>=2.0:../../textproc/p5-Text-SimpleTable

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/ObjectDriver/.packlist
PERL5_MODULE_TYPE=	Module::Install

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.605

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
