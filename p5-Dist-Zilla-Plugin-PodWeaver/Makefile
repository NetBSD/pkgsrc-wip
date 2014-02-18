# $NetBSD: Makefile,v 1.1 2014/02/18 04:06:34 jgoamakf Exp $

DISTNAME=	Dist-Zilla-Plugin-PodWeaver-4.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dist-Zilla-Plugin-PodWeaver/
COMMENT=	Weave your Pod together from configuration and Dist::Zilla
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Pod-Elemental-PerlMunger>=0.1:../../textproc/p5-Pod-Elemental-PerlMunger
DEPENDS+=	p5-Dist-Zilla>=5:../../devel/p5-Dist-Zilla
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Pod-Weaver>=4:../../textproc/p5-Pod-Weaver
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-File-Find-Rule>=0.03:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Dist/Zilla/Plugin/PodWeaver/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
