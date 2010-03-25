# $NetBSD: Makefile,v 1.1.1.1 2010/03/25 07:44:05 jgoamakf Exp $

DISTNAME=		TheSchwartz-1.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SI/SIXAPART/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/TheSchwartz/
COMMENT=		Reliable job queue system
LICENSE=		artistic-2.0

DEPENDS+=		p5-Data-ObjectDriver>=0.04:../../wip/p5-Data-ObjectDriver
DEPENDS+=		p5-Digest-MD5:../../security/p5-Digest-MD5
DEPENDS+=		p5-Storable:../../devel/p5-Storable

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TheSchwartz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
