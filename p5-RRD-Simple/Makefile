# $NetBSD: Makefile,v 1.5 2010/03/20 23:12:34 thomasklausner Exp $

DISTNAME=	RRD-Simple-1.43
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NI/NICOLAW/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RRD-Simple/
COMMENT=	RRD::Simple implementation for Perl
#LICENSE=	?

BUILD_DEPENDS+= p5-Test-Pod>=1.26:../../devel/p5-Test-Pod
BUILD_DEPENDS+= p5-Pod-Coverage>=0.18:../../textproc/p5-Pod-Coverage
BUILD_DEPENDS+= p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+= p5-Test-Deep>=0.096:../../devel/p5-Test-Deep

#PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/RRD/Simple/.packlist
MAKE_PARAMS+=		< /dev/null
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
