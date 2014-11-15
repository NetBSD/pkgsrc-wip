# $NetBSD: Makefile,v 1.9 2014/11/15 08:27:33 noud4 Exp $

DISTNAME=	Catalyst-Model-DBIC-Schema-0.65
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/G/GB/GBJK/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~gbjk/Catalyst-Model-DBIC-Schema/
COMMENT=	DBIx::Class::Schema Model Class

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Tie-IxHash>=0:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Storable>=0:../../devel/p5-Storable
DEPENDS+=	p5-MooseX-NonMoose>=0:../../devel/p5-MooseX-NonMoose
DEPENDS+=	p5-CatalystX-Component-Traits>=0:../../www/p5-CatalystX-Component-Traits
DEPENDS+=	p5-MooseX-Types-LoadableClass>=0:../../devel/p5-MooseX-Types-LoadableClass
DEPENDS+=	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0:../../databases/p5-DBIx-Class-Schema-Loader
DEPENDS+=	p5-Catalyst-Component-InstancePerContext>=0:../../www/p5-Catalyst-Component-InstancePerContext

PERL5_REQD+=	5.8.0

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/Schema/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
